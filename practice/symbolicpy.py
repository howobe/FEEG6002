import sympy as sy
from sympy.utilities.lambdify import lambdify
from sympy.utilities.codegen import codegen


def differentiate(syEquation, var):
    return sy.diff(syEquation, var)


def integrate(syEquation, var):
    return syEquation.integrate(var)


def solve(syEquation, var):
    return sy.solve(y, x)


x, y = sy.symbols("x y")
y = x**2 + 2 * x + 1

print(differentiate(y, x))
print(integrate(y, x))
print(solve(y, x))

yprime = differentiate(y, x)
ydiff = lambdify((x), yprime)
print(ydiff(-1))

code = codegen(('compute_ydiff', yprime), 'C', 'my_proj')
print(code)

for file in range(len(code)):
    with open(code[file][0], 'w') as fw:
        fw.write(code[file][1])
