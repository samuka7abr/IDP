public class Filme {
    private String titulo;
    public String getTitulo() {
        return titulo;
    }
    public void setTitulo(String titulo) {
        if(titulo.length() == 0){
            throw new IllegalArgumentException("o título não deve estar vazio");
        }else{
        this.titulo = titulo;
        }
    }

    private String diretor;
    public String getDiretor() {
        return diretor;
    }
    public void setDiretor(String diretor) {
        if(diretor.length() == 0){
            throw new IllegalArgumentException("o campo de diretor deve ser preenchido");
        }else{
            this.diretor = diretor;
        }
    }

    private int anoLancamento;
    public int getAnoLancamento() {
        return anoLancamento;
    }
    public void setAnoLancamento(int anoLancamento) {
        if(anoLancamento < 0){
            throw new IllegalArgumentException("O ano de lançamento não deve ser negativo");
        }else{
            this.anoLancamento = anoLancamento;
        }
    }

    private double nota;
    public double getNota() {
        return nota;
    }
    public void setNota(double nota) {
        if(nota < 0 || nota > 10){
            throw new IllegalArgumentException("A nota do filme deve ser entre 0 e 10");
        }else{
            this.nota = nota;
        }
    }

    public void exibirInfo(){
        System.out.println("\nTítulo: " + getTitulo());
        System.out.println("Diretor: " + getDiretor());
        System.out.println("Ano de Lançamento: " + getAnoLancamento());
        System.out.println("Nota: " + getNota());

    }
}
