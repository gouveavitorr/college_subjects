/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author 08220332
 */
public class Main {
    public static void main(String[] args) {
        
        Funcionario[] f = new Funcionario[6];
        
        Endereco e1 = new Endereco("Costa Gama", "Centro", "Osorio", "RS");
        f[0] = new Funcionario("Func", "1", 01, 0);
        f[0].setEndereco(e1);
        
        Endereco e2 = new Endereco("Rua das Flores", "Jardim América", "Porto Alegre", "RS");
        f[1] = new Funcionario("Maria Silva", "2", 02, 2000);
        f[1].setEndereco(e2);
        
        Endereco e3 = new Endereco("Av. Brasil", "Centro", "Gravataí", "RS");
        f[2] = new Funcionario("João Pereira", "3", 03, 2500);
        f[2].setEndereco(e3);
        
        Endereco e4 = new Endereco("Rua Dom Pedro", "Vila Nova", "Canoas", "RS");
        f[3] = new Funcionario("Ana Costa", "4", 04, 1800);
        f[3].setEndereco(e4);
        
        Endereco e5 = new Endereco("Rua Independência", "Centro", "São Leopoldo", "RS");
        f[4] = new Funcionario("Carlos Souza", "5", 05, 2200);
        f[4].setEndereco(e5);
        
        Endereco e6 = new Endereco("Rua Bento Gonçalves", "Cristo Rei", "Caxias do Sul", "RS");
        f[5] = new Professor("Fernanda Lima", "6", 06, 2100);
        f[5].setEndereco(e6);
        
        try{
            f[0].setSalario(9000.00);
            f[2].setSalario(3000.00);
            f[4].setSalario(-2000.00);
        }catch(IllegalArgumentException exception){
            System.out.println(exception.getMessage());
        }
        
        for (int i = 0; i < 6; i++) {
            System.out.println(f[i]);
        }
        
        //comparable and comparator pra ordenar os nomes em ordem alfabetica, valor de salario e determinada cidade
        
    }
}
