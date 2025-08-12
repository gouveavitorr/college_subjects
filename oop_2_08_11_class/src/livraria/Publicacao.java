package livraria;

import java.time.LocalDate;

public abstract class Publicacao {
    private String titulo;
    private LocalDate data;

    public Publicacao(String titulo, LocalDate data){
        this.titulo = titulo;
        this.data = data;
    }

    public String getTitulo(){
        return this.titulo;
    }

    public LocalDate data(){
        return this.data;
    }
}
