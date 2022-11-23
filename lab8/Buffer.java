import java.util.ArrayList;

class Buffer<T> {
    private ArrayList<T> buffer;
    private int tamanho;
    private int num_elementos;
    private int pos_insere;
    private int pos_retira;

    public Buffer(int tamanho) {
        this.tamanho = tamanho;
        this.buffer = new ArrayList<>(tamanho);
        // inicializa o buffer com as posições vazias
        for (int i = 0; i < tamanho; i++) this.buffer.add(null);
        // inicializa as variáveis de controle
        this.num_elementos = 0;
        this.pos_insere = 0;
        this.pos_retira = 0;
        System.out.println(this);
    }

    public synchronized void insere(int id, T elemento) {
        try {
            while (this.num_elementos == this.tamanho) {
                System.out.println("Produtor [" + id + "] foi bloqueado!");
                this.wait();
            }
            this.buffer.set(this.pos_insere, elemento);
            this.num_elementos++;
            this.pos_insere = (this.pos_insere + 1) % this.tamanho;
            // libera retirada do buffer
            this.notifyAll();

            System.out.println("Produtor [" + id + "] produziu " + elemento + ".");
            System.out.println(this.buffer);
        } catch (InterruptedException e) {};
    }

    public synchronized T retira(int id) {
        T elemento = null;
        try {
            while (this.num_elementos == 0) {
                System.out.println("Consumidor [" + id + "] foi bloqueado!");
                this.wait();
            }
            elemento = this.buffer.get(this.pos_retira);
            this.buffer.set(this.pos_retira, null);
            this.num_elementos--;
            this.pos_retira = (this.pos_retira + 1) % this.tamanho;
            // libera inserção no buffer
            this.notifyAll();

            System.out.println("Consumidor [" + id + "] consumiu " + elemento + ".");
            System.out.println(this.buffer);
        } catch (InterruptedException e) {};
        return elemento;
    }

    // imprimindo os elementos do buffer
    @Override
    public String toString() {
        return buffer.toString();
    }
}
