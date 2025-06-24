import numpy as np
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
plt.style.use("seaborn-v0 8-poster")
fig = plt.figure(figsize=(10,10) ) 



graphical visualization
# **np.linspace(start, stop, num)** 
# - This is a NumPy function that returns a set of evenly spaced numbers over a specified interval.

# - Parameters: <br>
#     start: The starting value of the sequence.

#     stop: The ending value of the sequence.

#     num: (the third argument) The number of values to generate between start and stop (inclusive).

# **plt.plot(x, y)**
# - Purpose: Plots y versus x as lines and/or markers.
# - Defaults:
#     It uses a blue solid line ('-b') by default.
#     You can customize it with arguments like plt.plot(x, y, 'ro--') for red circles with dashed lines.

# **plt.show( )**
# - Purpose: Displays the figure window containing the plot.
# - What it does:
#     Without plt.show(), your plot may not appear—especially in non-interactive environments (like scripts or some IDEs).
#     It starts the GUI event loop that renders the plot on screen.

# **plt.figure()**
# - Purpose: Creates a new figure (a blank canvas) for plotting.
# - Use case:
#     Useful when you're plotting multiple plots in a script.
#     Allows you to customize figure size, DPI, etc.

# **plt.xlabel() and plt.ylabel()**
#  - Purpose: Adds labels to the x-axis and y-axis.

# **plt.xlim() and plt.ylim()**
# - Purpose: Sets limits for the x-axis and y-axis.

# **plt.legend()**
# - Purpose: Displays a legend for the plot (helpful when multiple lines are plotted).
# - Needs: You must provide a label in plt.plot().

# **loc**
# - This parameter specifies the location of the legend.
# -  Common loc Values
#         You can use either strings or numbers to specify the location:

#         loc Value	Position
#         'best'	Let matplotlib decide (default)
#         'upper right'	Top-right corner
#         'upper left'	Top-left corner
#         'lower left'	Bottom-left corner
#         'lower right'	Bottom-right corner
#         'center'	Center of plot
#         'center left'	Middle left side
#         'center right'	Middle right side
#         'upper center'	Top center
#         'lower center'	Bottom center

# - you can also use numbers (0–10) instead of strings, but strings are more readable.
