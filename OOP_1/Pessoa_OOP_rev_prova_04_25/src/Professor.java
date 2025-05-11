/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author 08220332
 */
public class Professor extends Funcionario {
    
    public Professor(String nome, String sobrenome, int matricula, int salario) {
        super(nome, sobrenome, matricula, salario);
    }
    
    @Override
    public double getSalarioPrimeiraParcela(){
        
        double salarioAtual = getSalario();
        
        return salarioAtual;
    }
    
    @Override
    public double getSalarioSegundaParcela(){
        
        return 0;
    }
    
}
