public class Livro{
    public String title;
    public String author;
    public int date;

    public Livro(String title, String author, int date){
        this.title = title;
        this.author = author;
        this.date = date;
    }

    public static void main(String[] args){
        Livro livro1 = new Livro("O Senhor dos Anéis", "J.R.R Tolkien", 1954);

        System.out.println("Título: " + livro1.title + "\nAutor: " + livro1.author + "\nAno: " + livro1.date );
    }
}