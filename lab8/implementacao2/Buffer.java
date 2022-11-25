import java.util.ArrayList;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

class Buffer<T> {
    private ArrayList<T> buffer;
    private int tamanho;
    private int num_elementos;
    private int pos_insere;
    private int pos_retira;
    // para sincronização
    private ReentrantLock lock;
    private Condition fila_insere;
    private Condition fila_retira;

    public Buffer() {
        this(3); // tamanho default
    }

    public Buffer(int tamanho) {
        this.tamanho = tamanho;
        this.buffer = new ArrayList<>(tamanho);
        // inicializa o buffer com as posições vazias
        for (int i = 0; i < tamanho; i++) this.buffer.add(null);
        // inicializa as variáveis de controle
        this.num_elementos = 0;
        this.pos_insere = 0;
        this.pos_retira = 0;
        // inicializa as variáveis de sincronização
        this.lock = new ReentrantLock(true); // fairness = true
        this.fila_insere = lock.newCondition();
        this.fila_retira = lock.newCondition();
        System.out.println(this); // log
    }

    public void insere(int id, T elemento) {
        try {
            lock.lock();
            while (this.num_elementos == this.tamanho) {
                System.out.println("Produtor[" + id + "] se bloqueou!"); // log
                this.fila_insere.await();
            }
            this.buffer.set(this.pos_insere, elemento);
            this.num_elementos++;
            this.pos_insere = (this.pos_insere + 1) % this.tamanho;
            // libera retirada do buffer
            this.fila_retira.signal();
            System.out.println("Produtor[" + id + "] produziu " + elemento + "."); // log
            System.out.println(this.buffer); // log
        } catch (InterruptedException e) {
        } finally { // evitando deadlock caso ocorra algum problema
            lock.unlock();
        }
    }

    public T retira(int id) {
        T elemento = null;
        try {
            lock.lock();
            while (this.num_elementos == 0) {
                System.out.println("Consumidor[" + id + "] se bloqueou!"); // log
                this.fila_retira.await();
            }
            elemento = this.buffer.get(this.pos_retira);
            this.buffer.set(this.pos_retira, null);
            this.num_elementos--;
            this.pos_retira = (this.pos_retira + 1) % this.tamanho;
            // libera inserção no buffer
            this.fila_insere.signal();
            System.out.println("Consumidor[" + id + "] consumiu " + elemento + "."); // log
            System.out.println(this.buffer); // log
        } catch (InterruptedException e) {
        } finally { // evitando deadlock caso ocorra algum problema
            lock.unlock();
        }
        return elemento;
    }

    // retorna string contendo os elementos do buffer
    @Override
    public String toString() {
        return buffer.toString();
    }
}
