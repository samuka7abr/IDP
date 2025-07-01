public class Livro{
    public String title;
    public String author;
    public int date;

    public static void main(String[] args){
        Livro livro1 = new Livro();
        livro1.title = "O Senhor dos Anéis";
        livro1.author = "J.R.R Tolkien";
        livro1.date = 1954;

        System.out.println("Título: "+ livro1.title);
        System.out.println("Autor: "+ livro1.author);
        System.out.println("Ano: "+ livro1.date);

    }
}