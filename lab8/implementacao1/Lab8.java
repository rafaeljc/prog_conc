import java.util.ArrayList;

class Lab8 {
    private static Buffer<String> loja_frutas;
    private static int num_produtores;
    private static int num_consumidores;
    private static ArrayList<Thread> lista_produtores;
    private static ArrayList<Thread> lista_consumidores;

    private static void argumentoInvalido() {
        System.out.println("Argumento inválido!");
        System.out.println("Uso: java Lab8 [<num prod> <num cons>]");
        System.exit(1);
    }

    private static void trataArgumentosEntrada(String[] args) {
        switch (args.length) {
            case 2: // usa valores da entrada
                try {
                    num_produtores = Integer.parseInt(args[0]);
                    num_consumidores = Integer.parseInt(args[1]);
                    if (num_produtores < 1 || num_consumidores < 1) 
                        argumentoInvalido();
                } catch (NumberFormatException e) {
                    argumentoInvalido();
                }               
                break; 
            case 0: // usa valores default
                num_produtores = 1;
                num_consumidores = 1;
                break;
            default:
                argumentoInvalido();
        }
    }

    private static void instanciaThreads() {
        String[] lista_frutas = {"uva", "morango", "abacaxi", "banana"};
        lista_produtores = new ArrayList<>();
        for (int i = 0; i < num_produtores; i++) {
            Produtor<String> produtor = new Produtor<>(i + 1, loja_frutas, lista_frutas);
            lista_produtores.add(new Thread(produtor));
        }
        lista_consumidores = new ArrayList<>();
        for (int i = 0; i < num_consumidores; i++) {
            Consumidor<String> consumidor = new Consumidor<>(i + 1, loja_frutas);
            lista_consumidores.add(new Thread(consumidor));
        }
    }

    private static void iniciaThreads() {
        for (Thread t : lista_produtores) t.start();
        for (Thread t : lista_consumidores) t.start();
    }

    public static void main(String args[]) {
        trataArgumentosEntrada(args);
        loja_frutas = new Buffer<>();
        instanciaThreads();
        iniciaThreads();        
    }    
}
