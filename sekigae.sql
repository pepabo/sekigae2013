-- sekigae.sql
--
-- usage:
--   mysql    $ mysql   < sekigae.sql
--   postgres $ psql    < sekigae.sql
--   sqlite3  $ sqlite3 < sekigae.sql
--

/*!50000 USE test */;

CREATE TEMPORARY TABLE newcomers (
    name varchar(255)
);

INSERT INTO newcomers VALUES
    ('たけお'),
    ('きたけー'),
    ('ぐっさん'),
    ('おっくん');


/*!50000 DROP FUNCTION IF EXISTS random */;
/*!50000 CREATE FUNCTION random() RETURNS INT RETURN RAND() */;

SELECT * FROM newcomers ORDER BY random();

/*!50000 DROP FUNCTION IF EXISTS random */;
