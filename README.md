# Monte Carlo Probability Tester
Author: John Tristan Ritland
Version: v0.2

a way to analyze the odds of a system giving a certain result. Because I don't have time to actualy teach myself statistics.

## more specificaly...

Okay, so I didn't realy know what I was doing when I started this, but as it turns out, there's a word for what I'm making: A [Bayesian Network solver](https://en.wikipedia.org/wiki/Bayesian_network) based off the [Monte Carlo Method](https://en.wikipedia.org/wiki/Monte_Carlo_method) The node network is a [Directed Acyclic Graph](https://en.wikipedia.org/wiki/Directed_acyclic_graph)

I hope to implement this using the Boost::Graph library, but my code doesn't reflect that at the moment. It's still a variant that was going to use my own implementation of the Coffman-Graham algorithm. Before that, I was hoping to get away with using a basic tree, or random walk. Which didn't work at all.

[at the risk of seeming unprofessional](http://i.imgur.com/USmiwaf.jpg)


## History of this idea

I should probably mention that this is a continuation of a college assignment, in which I did a similar thing, except with a highly specific case, which eliminated most of the difficulties innate in this one: A network of nodes with a certain probability of failure. It was implemented by an array to store the nodes (since I didn't understand pointers yet), and each iteration, the system would evaluate the nodes, to see if a input "1" made it through the network to the exit node, or if it failed along the way. This variant did support cycles, as with this specific problem, they would always converge to zero probability.

## License
![GNU GPLv3 Image](https://www.gnu.org/graphics/gplv3-127x51.png)

This program is Free Software: You can use, study share and improve it at your
will. Specifically you can redistribute and/or modify it under the terms of the
[GNU General Public License](https://www.gnu.org/licenses/gpl.html) as
published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
