package livraria;

import java.time.LocalDate;

public class Livro extends Publicacao {

    private int paginas;
    private String[] autores;

    public Livro(String titulo, LocalDate data, int paginas, String[] autores) {
        super(titulo, data);
        this.paginas = paginas;
        this.autores = autores;
    }
    
    public int getPaginas(){
        return this.paginas;
    }

    public String[] getAutores(){
        return this.autores;
    }
}
