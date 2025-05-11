/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package projetorevisao;

/**
 *
 * @author karen
 */
public class Funcionario extends Pessoa implements Comparable {
    private int matricula;
    private double salario;

    public Funcionario(String nome, String sobrenome, int matricula, double salario) {
        super(nome, sobrenome);
        this.matricula = matricula;
        setSalario(salario);
    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) throws IllegalArgumentException {
        if (salario < 0) {
            throw new IllegalArgumentException("O salario nao pode ser negativo");
        }
        this.salario = salario;
    }
    
    public double getSalarioPrimeiraParcela() {
        return salario * 0.6;
    }
    
    public double getSalarioSegundaParcela() {
        return salario * 0.4;
    }

    @Override
    public String toString() {
        return super.toString() + "Funcionario{" + "matricula=" + matricula + ", salario=" + salario + '}';
    }
    
    @Override
    public int compareTo(Object obj) {
        int retorno = 0;
        if (obj != null && obj instanceof Funcionario){
            Funcionario outro = (Funcionario) obj;
            retorno = this.getNome().compareTo(outro.getNome());
        }
        return retorno;
    }
}
