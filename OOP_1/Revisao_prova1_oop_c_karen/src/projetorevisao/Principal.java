/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package projetorevisao;
import java.util.Arrays;
import javax.swing.JOptionPane;

/**
 *
 * @author karen
 */
public class Principal {
    public static void main(String[] args) {
        try {
            Funcionario[] f = new Funcionario[6];

            Endereco e1 = new Endereco("Costa Gama", "Centro", "Osorio", "RS");
            f[0] = new Funcionario("Func", "1", 01, 0);
            f[0].setEndereco(e1);

            Endereco e2 = new Endereco("Rua das Flores", "Jardim América", "Porto Alegre", "RS");
            f[1] = new Funcionario("Maria Silva", "2", 02, 2000);
            f[1].setEndereco(e2);

            Endereco e3 = new Endereco("Av. Brasil", "Centro", "Gravatai", "RS");
            f[2] = new Funcionario("João Pereira", "3", 03, 2500);
            f[2].setEndereco(e3);

            Endereco e4 = new Endereco("Rua Dom Pedro", "Vila Nova", "Canoas", "RS");
            f[3] = new Funcionario("Ana Costa", "4", 04, 1800);
            f[3].setEndereco(e4);

            Endereco e5 = new Endereco("Rua Independência", "Centro", "Sao Leopoldo", "RS");
            f[4] = new Funcionario("Carlos Souza", "5", 05, 2200);
            f[4].setEndereco(e5);

            Endereco e6 = new Endereco("Rua Bento Gonçalves", "Cristo Rei", "Osorio", "RS");
            f[5] = new Professor("Fernanda Lima", "6", 06, 2100);
            f[5].setEndereco(e6);

            String s = JOptionPane.showInputDialog("Escolha uma das opcoes:"
                    + "\n 1 - Ordenar pelo nome"
                    + "\n 2 - Ordenar pelo pelo salario"
                    + "\n 3 - Mostrar pela cidade");

            int n = Integer.parseInt(s);

            switch(n){
                case 1: Arrays.sort(f);
                    for (int i = 0; i < 6; i++) {
                        System.out.println(f[i]);
                    }
                    break;
                case 2: Arrays.sort(f, new SortBySalary());
                    for (int i = 0; i < 6; i++) {
                        System.out.println(f[i]);
                    }
                    break;
                case 3: 
                    String chosenCity = JOptionPane.showInputDialog("Escreva o nome da cidade: ");
                    for (int i = 0; i < 6; i++) {
                        String cidade = f[i].getEndereco().getCidade().toLowerCase();
                        if (cidade.equals(chosenCity.toLowerCase())) {
                            System.out.println(f[i]);
                        }
                    }
                    break;
            }
        } catch (IllegalArgumentException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}
