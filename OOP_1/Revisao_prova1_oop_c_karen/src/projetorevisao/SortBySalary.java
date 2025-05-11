/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package projetorevisao;

import java.util.Comparator;

/**
 *
 * @author karen
 */
class SortBySalary implements Comparator {
    public int compare(Object obj1, Object obj2) {
        Funcionario a = (Funcionario) obj1;
        Funcionario b = (Funcionario) obj2;
        
        if(a.getSalario() < b.getSalario()) return -1;
        if(a.getSalario() > b.getSalario()) return 1;
        return 0;
    }
}
