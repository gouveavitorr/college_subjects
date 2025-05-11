/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author 08220332
 */


public class Funcionario extends Pessoa {
    
    private int matricula;
    private double salario;

    public Funcionario(String nome, String sobrenome, int matricula, int salario) {
        super(nome, sobrenome);
        this.matricula = matricula;
        this.salario = salario;
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
        
        if(salario < 0){
            throw new IllegalArgumentException("O salario nao pode ser negativo");
        }
        
        //resolver o exception usando try catch onde vá se chamar o setSalario
        
        this.salario = salario;
    }
    
    public double getSalarioPrimeiraParcela(){
        
        double salarioAtual = getSalario();
        
        return salarioAtual * 0.6;
    }
    
    public double getSalarioSegundaParcela(){
        
        double salarioAtual = getSalario();
        
        return salarioAtual * 0.4;
    }

    @Override
    public String toString() {
        return super.toString() + "Funcionario{" + "matricula=" + matricula + ", salario=" + salario + '}';
    }
    
    
}
