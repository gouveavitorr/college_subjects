--views are saved queries. Everytime you call a view, it redoes the query, so nothing from the table is really saved
    
    CREATE VIEW <view_name> [optional col names] AS (SELECT...)
    DROP VIEW <view_name>
    CREATE VIEW view_empregado AS (
        SELECT nome, cpf, datanascimento
            FROM empregado
    );

--materialized views are saved queries as tables, and they demand more
    
    CREATE MATERIALIZED VIEW <view_name> AS (SELECT...)
    DROP MATERIALIZED VIEW <view_name>

--DBMS (database management system) or SGBD in ptbr

--indexes
    CREATE INDEX <index_name> ON <table_name>(<col_name>)
    DROP INDEX <index_name>

--transactions
    BEGIN TRANSACTION;
    ROLLBACK WORK; --failsafe during the transaction, and cannot be used after committing
    COMMIT WORK; --end of the transaction

