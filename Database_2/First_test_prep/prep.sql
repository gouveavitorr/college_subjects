
--adding a sequence
CREATE SEQUENCE "bookIdSequence";

ALTER TABLE book ALTER COLUMN id SET DEFAULT nextval('"bookIdSequence"');

--removing the sequence from the column
ALTER TABLE book ALTER COLUMN id DROP DEFAULT;

ALTER TABLE book ALTER COLUMN title SET NOT NULL;
ALTER TABLE book ALTER COLUMN title DROP NOT NULL;
ALTER TABLE book DROP CONSTRAINT "book_PK";



