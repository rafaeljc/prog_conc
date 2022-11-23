import java.util.ArrayList;

class Lab8 {
    public static void main(String args[]) {
        Buffer<String> loja_frutas = new Buffer<>(3);
        String[] lista_frutas = {"uva", "morango"};

        ArrayList<Thread> lista_produtores = new ArrayList<>();
        for (int i = 0; i < lista_frutas.length; i++) {
            Produtor<String> produtor = new Produtor<>(i + 1, lista_frutas[i], loja_frutas);
            lista_produtores.add(new Thread(produtor));
        }
        
        ArrayList<Thread> lista_consumidores = new ArrayList<>();
        for (int i = 0; i < 2; i++) {
            Consumidor<String> consumidor = new Consumidor<>(i + 1, loja_frutas);
            lista_consumidores.add(new Thread(consumidor));
        }

        for (Thread t : lista_produtores) t.start();
        for (Thread t : lista_consumidores) t.start();
    }    
}
