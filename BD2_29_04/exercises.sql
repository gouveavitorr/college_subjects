-- 1- Faça uma consulta que retorne os dados de cada nota fiscal e o nome do cliente que realizou a compra.

SELECT notafiscal.*, cliente.nome AS comprador 
FROM notafiscal 
JOIN cliente 
ON cliente.codcliente = notafiscal.codcliente;

-- 2- Busque os dados de nota fiscal e o nome do funcionário que realizou a venda.

SELECT n.*, f.nome AS vendedor 
FROM notafiscal n 
JOIN funcionario f 
ON f.codFuncionario = n.codfuncionario;

-- 3- Sobre a tabela ItemVenda, mostre todos os seus dados bem como a descrição de cada produto referente a cada item de venda.

SELECT i.*, p.descricao 
FROM itemvenda i 
JOIN produto p 
ON p.codproduto = i.codproduto;

-- 4- Busque os dados de nota fiscal e quantos items foram vendidos em cada venda.

SELECT n.*, count(i.*) 
FROM notafiscal n 
JOIN itemvenda i 
ON n.codnotafiscal = i.codnotafiscal
GROUP BY n.codnotafiscal;

-- 5- Faça uma consulta nos funcionários que demonstre os dados dos funcionários e um dado extra de classificação, o tipo salario (uma nova coluna extraída do salário), conforme a tabela:

-- tipo salario	faixa salarial
-- "alto"	acima de 8000
-- "médio"

-- entre 4000 e 8000
-- "baixo"

-- abaixo de 4000
-- 6- Faça uma consulta nos funcionários que demonstre os dados dos funcionários e um dado extra de classificação, a faixa etária (uma nova coluna extraída da data nascimento), conforme a tabela:

-- faixa etária	faixa salarial
-- "jovem"	idade abaixo de 30
-- "adulto"

-- idade entre 30 e 60
-- "idoso"

-- idade maior ou igual a 60

-- 7- Considerando o exercício 5, refaça a consulta mostrando também o nome do departamento de cada funcionário.

-- 8- Considerando o exercício 5, faça uma consulta que retorne a média salarial e total de funcionários por "tipo salario", ordene pelo total de funcionários.

-- 9 - Liste para cada departamento (nome do departamento) o total de funcionários que trabalham no respectivo departamento

-- 10 - Considerando o exercício 5, liste o número de vendas realizadas por todos empregados de cada faixa salarial