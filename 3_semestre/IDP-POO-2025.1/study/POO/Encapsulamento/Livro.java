public class Livro{
    private String title;
    public void setTitle(String title) {
        if(title.length() == 0){System.out.println("não pode estar vazio");
        }else{
        this.title = title;
        }
    }
    public String getTitle() {
        return title;
    }
    
    private String author;
    public void setAuthor(String author) {
        this.author = author;
    }
    public String getAuthor() {
        return author;
    }

    private int ano;
    public void setAno(int ano) {
        if(ano < 0){System.out.println("O valor do lançamento não pode ser negativo");
        }else{
            this.ano = ano;
        }
    }
    public int getAno() {
        return ano;
    }


    public static void main(String[] args){
        Livro livro1 = new Livro();
        livro1.setTitle("O Senhor dos Anéis");
        livro1.setAuthor("J.R.R Tolkien");
        livro1.setAno(1954);

        System.out.println("Título: " + livro1.getTitle() + "\nAuthor: " + livro1.getAuthor() + "\nAno: " + livro1.getAno());
    }   

}

/*para usar get e set com scanner:
    livro.setTitle(scanner.nextLine());

 */