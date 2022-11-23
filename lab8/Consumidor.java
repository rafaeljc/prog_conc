
class Consumidor<T> implements Runnable {
    private int id;
    private Buffer<T> buffer;

    public Consumidor(int id, Buffer<T> buffer) {
        this.id = id;
        this.buffer = buffer;
    }

    public void run() {
        T elemento = null;
        while (true) {
            elemento = this.buffer.retira(this.id);
            // "processa elemento"
            for (int i = 0; i < 100_000_000; i++);
        }
    }
}
