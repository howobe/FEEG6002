import sys
import pylab

if len(sys.argv) > 1:
    filename = sys.argv[1]
else:
    filename = "data.txt"


data = pylab.loadtxt(filename)

x = data[:, 0]
ys = data[:, 1]
pylab.plot(x, ys, '-o')
pylab.grid()
# if desired, save to file by uncommenting the next line(s)
# pylab.savefig('dataplot.png')
pylab.savefig('dataplot.pdf')
pylab.show()
