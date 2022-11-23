
class Produtor<T> implements Runnable {
    private int id;
    private T elemento;
    private Buffer<T> buffer;

    public Produtor(int id, T elemento, Buffer<T> buffer) {
        this.id = id;
        this.elemento = elemento;
        this.buffer = buffer;
    }
    
    public void run() {
        while (true) {
            this.buffer.insere(this.id, this.elemento);
            // faz nada
            for (int i = 0; i < 100_000_000; i++);
        }
    }
}
