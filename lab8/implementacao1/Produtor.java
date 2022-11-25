import java.util.concurrent.ThreadLocalRandom;

class Produtor<T> implements Runnable {
    private int id;
    private Buffer<T> buffer;
    private T[] lista_elementos;

    public Produtor(int id, Buffer<T> buffer, T[] lista_elementos) {
        this.id = id;
        this.buffer = buffer;
        this.lista_elementos = lista_elementos;
    }

    private T produzElemento() {        
        // simula que produzir elemento "da trabalho"
        for (int i = 0; i < 100_000_000; i++);
        // escolhe aleatoriamente um dos elementos da lista
        int n = ThreadLocalRandom.current().nextInt(0, lista_elementos.length);
        return lista_elementos[n];
    }
    
    public void run() {
        while (true) {
            T elemento = produzElemento();
            this.buffer.insere(this.id, elemento);            
        }
    }
}
