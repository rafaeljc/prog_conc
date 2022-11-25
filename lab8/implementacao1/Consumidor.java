
class Consumidor<T> implements Runnable {
    private int id;
    private Buffer<T> buffer;

    public Consumidor(int id, Buffer<T> buffer) {
        this.id = id;
        this.buffer = buffer;
    }

    private void consomeElemento(T elemento) {
        // simula consumo do elemento
        for (int i = 0; i < 100_000_000; i++);
    }

    public void run() {
        while (true) {
            T elemento = this.buffer.retira(this.id);
            consomeElemento(elemento);
        }
    }
}
