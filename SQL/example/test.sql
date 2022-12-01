CREATE TABLE nameTab(
  id INT PRIMARY KEY NOT NULL,
  name TEXT NOT NULL,
  age TEXT NULL
);

CREATE TABLE nameTab2(
  id INT PRIMARY KEY NOT NULL,
  job TEXT NOT NULL,
  FOREIGN KEY (id) REFERENCES nameTab(id)
);

INSERT INTO nameTab2(id, job) VALUES (0, "Joe");
INSERT INTO nameTab2(id, job) VALUES (1, "Racteur");
INSERT INTO nameTab2(id, job) VALUES (2, "Robot");
INSERT INTO nameTab2(id, job) VALUES (3, "Joe");
INSERT INTO nameTab2(id, job) VALUES (4, "Ralph");
INSERT INTO nameTab2(id, job) VALUES (5, "Joe");
