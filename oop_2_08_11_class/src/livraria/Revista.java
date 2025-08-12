package livraria;

import java.time.LocalDate;

public class Revista extends Publicacao {

    private int edicao;
    private String editora;

    public Revista(String titulo, LocalDate data, String editora, int edicao) {
        super(titulo, data);
        this.edicao = edicao;
        this.editora = editora;
    }

    public int getEdicao(){
        return this.edicao;
    }

    public String getEditora(){
        return this.editora;
    }
    
}
