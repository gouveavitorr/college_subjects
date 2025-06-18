-- prova: 6-junções, 7-views, índices, transações, 8-procedures, 9-triggers

--😍😍😍😍😍😍😍😍views nao podem ter nomes de colunas duplicados porque causa ambiguidade
--lembrar begin transaction e commit work. faremos insert, delete, update dentro disso, sem select. precisamos saber como agrupar as queries que fazem parte de um mesmo processo, uma mesma transação
--view: CREATE VIEW antes de tudo. colunas não podem repetir o nome

--a. O nome dos funcionários e de seus respectivos departamentos.
SELECT f.nome, d.nome FROM funcionario f
    LEFT JOIN departamento d ON d.coddepartamento = f.coddepartamento;

--b. Quantas diferentes pessoas (todos seus dados) existem no banco de dados (clientes e funcionários).
SELECT c.*, f.* FROM cliente c
    FULL JOIN funcionario f ON f.cpf = c.cpf;

--c. Liste a média salarial, o maior e menor salário dos funcionários agrupado por nome do departamento e ordenado pelo nome do departamento para funcionários do sexo masculino com salário maior que 2000
SELECT d.nome "NomeDepto" avg(f.salario), max(f.salario), min(f.salario) from funcionario f
    LEFT JOIN departamento d ON d.coddepartamento = f.coddepartamento
    WHERE f.sexo = 'M' AND f.salario > 2000
    GROUP BY d.nome
    ORDER BY d.nome;

--d. A descrição dos produtos bem como o número de itens que foram vendidos, ordenado pelo número de itens que foram vendidos.
SELECT p.descricao, sum(iv.quantidade) "itensVendidos" FROM produto p
    LEFT JOIN itemvenda iv ON iv.codproduto = p.codproduto
    GROUP BY p.codproduto
    ORDER BY "itensVendidos" ASC;

--e. A descrição e número de vezes que cada produto foi vendido, ordenado pelo número de vezes que foi vendido.
SELECT p.descricao, count(iv.*) "itensVendidos" FROM produto p
    LEFT JOIN itemvenda iv ON iv.codproduto = p.codproduto
    GROUP BY p.codproduto --sem o group by, a quantidade de linhas difere por conta do count
    ORDER BY "itensVendidos" DESC;

--f. A lista dos clientes que mais vezes compram na loja. Nome e total de compras ordenado pelo total de compras.
SELECT c.nome, count(iv.*) "itensComprados" FROM cliente c
    LEFT JOIN notafiscal nf ON nf.codcliente = c.codcliente
    LEFT JOIN itemvenda iv ON iv.codproduto = nf.codproduto
    GROUP BY iv.codproduto
    ORDER BY "itensComprados" DESC;

--g. A lista dos funcionários que mais vendas realizaram. Nome e total de vendas realizadas ordenado pelo total de compras.
SELECT f.nome, max(count(iv.*)) "itensVendidos" FROM funcionario f
    LEFT JOIN notafiscal nf ON nf.codfuncionario = f.codfuncionario
    LEFT JOIN itemvenda iv ON iv.codproduto = nf.codproduto
    GROUP BY f.nome
    ORDER BY "itensVendidos" DESC;

--h. A lista de dos departamentos e o total em vendas (R$) realizadas por cada departamento
SELECT d.*, sum(iv.precounitvenda * iv.quantidade) "totalVendas" FROM departamento d
    LEFT JOIN funcionario f ON f.coddepartamento = d.coddepartamento
    LEFT JOIN 

