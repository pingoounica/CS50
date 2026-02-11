pre = [
    ('george', 1789),
    ('john', 1797),
    ('thomas',1801),
    ('james madison', 1809)
]
for prez, year in pre:
    print('in {1}, {0} took office.'.format(prez,year))

pizzas = {
    'cheese': 9,
    'pepperoni': 10,
    'vegetable': 11,
    'buffalo': 12
}

for k,v in pizzas.items():
    print(k,v)

class Student():

    def __init__(self, name, id):
        self.name = name
        self.id = id

    def changeID(self,id):
        self.id = id
        print('{} - {}'.format(self.name, self.id))

        jane = Student('Jane',10)
        jane.print()
        jane.changeID(11)
        jane.print()