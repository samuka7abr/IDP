public class Main {
    public static void main(String[] args){
        Cachorro c1 = new Cachorro("Rex", 3);
        Gato g1 = new Gato("Luna", 2);

        c1.exibirInfo();
        c1.fazerSom();
        System.out.println("");
        g1.exibirInfo();
        g1.fazerSom();

    }
}
