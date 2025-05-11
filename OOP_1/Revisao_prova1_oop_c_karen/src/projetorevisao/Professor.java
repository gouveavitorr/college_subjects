/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package projetorevisao;

/**
 *
 * @author karen
 */
public class Professor extends Funcionario {

    public Professor(String nome, String sobrenome, int matricula, double salario) {
        super(nome, sobrenome, matricula, salario);
    }
    
    @Override
    public double getSalarioPrimeiraParcela() {
        return getSalario();
    }
    
    @Override
    public double getSalarioSegundaParcela() {
        return 0;
    }
    
    @Override
    public String toString() {
        return "Professor(a):" + super.toString();
    }
    
    
}
