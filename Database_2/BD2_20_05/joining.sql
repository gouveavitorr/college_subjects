-- JOIN uses ON, but there's "USING" but its usage is very specific


--INNER is the default value for JOIN
SELECT * FROM employee e INNER JOIN depto d ON d.deptID = e.deptID;
--INNER brings connections between the two tables that satisfy the condition

--FULL/LEFT/RIGHT JOIN

--LEFT JOIN
SELECT * FROM employee e LEFT JOIN depto d ON d.deptID = e.deptID;
--brings all the values from employee even when it doesn't satisfy
--the condition, and then puts null on the right when needed

--RIGHT JOIN
SELECT * FROM employee e RIGHT JOIN depto d ON d.deptID = e.deptID;
--brings all the values from depto and then fills the left with null
--when it doesn't satisfy the condition there

--FULL JOIN
SELECT * FROM employee e FULL JOIN depto d ON d.deptID = e.deptID;
--brings all the values from both while avoiding repetitions and filling
--with null values the remaining elements

--a. O nome dos funcionários e de seus respectivos departamentos
SELECT f.nome, d.nome FROM funcionario f LEFT JOIN departamento d ON f.coddepartamento = d.coddepartamento;

--b. Quantas diferentes pessoas (todos seus dados) existem no banco de dados (clientes e funcionários).
SELECT c.*, f.*  FROM cliente c FULL JOIN funcionario f ON c.nome = f.nome;

--c. Liste a média salarial, o maior e menor salário dos funcionários agrupado por nome do departamento e
--ordenado pelo nome do departamento para funcionários do sexo masculino com salário maior que 2000
SELECT d.nome "NomeDepto", 
	ROUND(AVG(f.salario), 2) "mediaSalario", 
	MAX(f.salario) "MaxSalario", 
	MIN(f.salario) "MinSalario" 
	FROM departamento d 
	INNER JOIN funcionario f
	ON f.coddepartamento = d.coddepartamento
	WHERE f.sexo = 'M' AND f.salario > 2000
	GROUP BY d.nome
	ORDER BY d.nome;

--d. A descrição dos produtos bem como o número de itens que foram vendidos, ordenado pelo número de itens que foram vendidos.
SELECT p.descricao, SUM(i.quantidade)::INTEGER
	FROM produto p LEFT JOIN itemvenda i
	ON p.codproduto = i.codproduto
	GROUP BY p.descricao
	ORDER BY SUM(i.quantidade) DESC;
	
--e. A descrição e número de vezes que cada produto foi vendido, ordenado pelo número de vezes que foi vendido.
SELECT p.descricao, ROUND(COUNT(i.*))
	FROM produto p LEFT JOIN itemvenda i
	ON p.codproduto = i.codproduto
	GROUP BY p.descricao
	ORDER BY COUNT(i.quantidade) DESC;

--f. As listas dos clientes que mais vezes compram na loja. Nome e total de compras ordenado pelo total de compras.
SELECT c.nome "Cliente gastador", COUNT(n.*) "Numero de compras" 
	FROM cliente c INNER JOIN notafiscal n
	ON c.codcliente = n.codcliente
	GROUP BY c.nome
	ORDER BY COUNT(n.*) DESC;

--g. A lista dos funcionários que mais vendas realizaram. Nome e total de vendas realizadas ordenado pelo total de compras.
SELECT f.nome "Func foda", COUNT(n.*) "Numero de vendas"
	FROM funcionario f INNER JOIN notafiscal n
	ON f.codfuncionario = n.codfuncionario
	GROUP BY f.nome
	ORDER BY COUNT(n.*) DESC;

select * from itemvenda;

--h. A lista dos departamentos e o total em vendas (R$) realizadas por cada departamento.
SELECT d.coddepartamento, d.nome, COALESCE(SUM(i.quantidade * i.precounitvenda), 0) "Total em vendas"
	FROM departamento d 
	LEFT JOIN funcionario f
	ON d.coddepartamento = f.coddepartamento
	LEFT JOIN notafiscal n
	ON n.codfuncionario = f.codfuncionario
	LEFT JOIN itemvenda i
	ON n.codnotafiscal = i.codnotafiscal
	GROUP BY d.coddepartamento
	ORDER BY "Total em vendas" DESC;
	
--i. Sobre os clientes que são funcionários mostrar o nome, o total em vendas realizadas (R$) e o total em compras realizadas (R$)
WITH clientes AS (

	SELECT c.nome cliente_nome, c.cpf, COALESCE(SUM(i.precounitvenda * i.quantidade), 0) "TotalVendido"--, COALESCE(SUM(precocompra * compraqtd), 0) "TotalCompras"
		FROM cliente c
		INNER JOIN notafiscal n ON c.codcliente = n.codcliente
		RIGHT JOIN itemvenda i ON i.codnotafiscal = n.codnotafiscal
		GROUP BY c.codcliente

),

funcionarios AS (
	SELECT f.nome funcionario, f.cpf, COALESCE(SUM(i.precounitvenda * i.quantidade), 0) "TotalComprado"
		FROM funcionario f
		INNER JOIN notafiscal n ON f.codfuncionario = n.codfuncionario
		RIGHT JOIN itemvenda i ON i.codnotafiscal = n.codnotafiscal
		GROUP BY f.codfuncionario
)

SELECT clientes.cliente_nome nome, funcionarios."TotalVendido", clientes."TotalComprado"
	FROM funcionarios
	INNER JOIN clientes USING (cpf);

--j. O nome e a média em compras (R$) para os clientes que compraram em média acima de R$30 em cada compra.
WITH notas AS (
	SELECT nf.*, SUM(iv.quantidade * iv.precounitvenda ) AS total_nota
		FROM itemvenda iv
		INNER JOIN notafiscal nf ON iv.codnotafiscal = nf.codnotafiscal
		GROUP BY nf.codnotafiscal
		ORDER BY nf.codcliente
	)
SELECT notas.codcliente, AVG(total_nota) avg_nota
	FROM notas INNER JOIN cliente c ON c.codcliente = notas.codcliente
	GROUP BY c.codcliente
	HAVING avg_nota > 30

--where filtra antes de agrupar e having filtra depois de agrupar

--k. Nome do cliente, do funcionário e o total da compra para vendas realizadas no último mês.
SELECT c.nome, f.nome, nf.*, SUM(iv.quantidade * iv.precounitvenda) AS total_nota
	FROM itemvenda iv
		INNER JOIN notafiscal nf ON iv.codnotafiscal = nf.codnotafiscal
		INNER JOIN funcionario f ON f.codfuncionario = nf.codfuncionario
		INNER JOIN cliente c ON c.codcliente = nf.codcliente
	WHERE datavenda > (current_date - interval '30 days')
	GROUP BY nf.codnotafiscal, c.nome, f.nome;