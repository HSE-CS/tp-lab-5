import faker
import random

id = 0
gid = 0
f = faker.Faker("ru_RU")
o = open("db", "w")
for _ in range(10):
    o.write("group " + f.safe_color_name() + str(gid) + " " + f.safe_color_name() + " " + str(id) + "\n")
    for _ in range(random.randrange(12, 24)):
        mark_num = random.randrange(5, 15)
        o.write("  " + f.first_name() + " " + f.middle_name() + " " + f.last_name() + " " + str(id) + " " + str(mark_num))
        for _ in range(mark_num):
            o.write(" "+str(random.randrange(0, 10)))
        o.write("\n")
        id += 1
    o.write("endgroup\n")
    gid += 1

