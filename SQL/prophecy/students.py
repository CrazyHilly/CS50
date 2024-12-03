import sqlite3


db = sqlite3.connect("roster.db")
my_db = sqlite3.connect("my.db")


rows = db.execute("SELECT * FROM students")
for row in rows:
    student_id = row[0]
    house_name = row[2]

    cur = my_db.cursor()
    cur.execute("SELECT house_id FROM houses WHERE house_name = ?", (house_name,))
    res = cur.fetchone()
    house_id = res[0]
#    print(type(student_id), type(house_id))
    assignment = (student_id, house_id)
    cur.execute("INSERT INTO assignments VALUES(?, ?)", assignment)
    my_db.commit()