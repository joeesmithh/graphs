# Graph Visualizer

A C++/Qt application for creating, visualizing, and interacting with graphs.  
This project implements graph data structures (adjacency list and adjacency matrix) with a unified interface, and provides a GUI for building and traversing graphs in real-time.

<br>

## Features

- **Graph Implementations**  
  - `ListGraph`: Directed, weighted adjacency list representation.  
  - `MatrixGraph`: Directed, weighted adjacency matrix representation.  
  - `GraphInterface`: Abstract interface ensuring consistent operations across implementations.  

- **GUI (Qt-based)**  
  - Create and connect vertices interactively.  
  - Real-time graph visualization using `QGraphicsView`.  
  - Menu-driven controls for adding vertices and traversals.  

- **Core Functionality**  
  - Add vertices and edges dynamically.  
  - Track number of vertices and edges.  
  - Traversal support with reset mechanisms.  


<br>

## Demo
<table>
    <tr>
        <th>Vertex Creation</th>
        <th>Depth-First Traversal</th>
    </tr>
    <tr align="center">
        <td>
            <img src="./images/graphs_add_vertices.gif">
        </td>
        <td >
            <img src="./images/graphs_traverse.gif">
        </td>
    </tr>
</table>

<br>

## Project Structure
- `GraphInterface.h` – Abstract class defining graph operations
- `MatrixGraph.h / .cpp` – Adjacency matrix graph implementation
- `ListGraph.h / .cpp` – Adjacency list graph implementation
- `GraphVertex.h / .cpp` - Data container managed by ListGraph
- `GUIGraph.h / .cpp` – Graph GUI integration using Qt
- `GUIVertex.h / .cpp` – Vertex GUI integration using Qt
- `main_window.*` – Main application window setup
- `create_vertex_dialog.*` – Dialog for adding vertices

<br>

## Future Improvements
- Add breadth-first and depth-first traversal visualization.
- Support for weighted edge editing via GUI.
- Export/import graphs to file formats (JSON, CSV).

<br>

## Getting Started

### Prerequisites
- **C++17 or later**
- **Qt 5 or 6** development libraries
- **Qt VS Tools** extension

### Build Instructions
```bash
# Clone the repository
git clone https://github.com/joeesmithh/graphs.git
```
- Open `graphs.sln`
- **Qt Project Settings**
    - Specify **Qt Installation**
    - Specify **Qt Modules**, `core;gui;widgets`

<!--- ## Implementation
<table>
    <tr>
        <th>Object</th>
        <th>Purpose</th>
        <th>Key Members</th>
        <th>Key Operations</th>
    </tr>
    <tr valign="top">
        <td>
            <strong>GraphVertex&lt;T&gt;</strong>
        </td>
        <td >
            Represents a graph vertex for an adjacency list implementation of the graph data structure.
        </td>
        <td>
            <code><strong>data</strong></code>: the data contained within the vertex<br>
            <code><strong>edges</strong></code>: a list of other GraphVertex objects, represents directed edges<br>
        </td>
        <td >
            <code><strong>connectTo</strong></code>: forms a directed edge to GraphVertex parameter by adding it to the edges list.<br>
            <code><strong>depthFirst</strong></code>: performs a recursive traversal on all directed edges, calls lambda function parameter for each visited vertex
        </td>
    </tr>
    <tr valign="top">
        <td>
            <strong>ListGraph&lt;T&gt;</strong>
        </td>
        <td >
            Represents an adjacency list implementation of the graph data structure.
        </td>
        <td >
            <code><strong>root</strong></code>: pointer to the root vertex of the graph<br>
            <code><strong>traversedStack</strong></code>: dynamic stack containing traversed GraphVertex objects in reverse order of last traversal, used to clear vertex traversal flags<br>
            <code><strong>traversedOrderStack</strong></code>: dynamic stack containing traversed GraphVertex objects in order of the last traversal, used for visiting vertices in traversal order only when desired
        </td>
        <td>
            <code><strong>add</strong></code>: creates a directed edge in the graph between two <strong>GraphVertex</strong> objects with data matching arguments<br>
            <code><strong>depthFirst</strong></code>: Performs a depth-first traversal on the graph from the root vertex, calls lambda function parameter for each visited <strong>GraphVertex</strong><br>
            <code><strong>depthStep</strong></code>: Step through a depth-first traversal by visiting the top-most item from the <strong>traverseOrderStack</strong>
            <code><strong>untraverse</strong></code>: Pops traversed <strong>GraphVertex</strong> objects from <storng>traversedStack</storng>, calling lambda function parameter for each popped <strong>GraphVertex</strong>
        </td>
    </tr>
    <tr valign="top">
        <td>
            <strong>GUIVertex</strong>
        </td>
        <td >
            [...]
        </td>
        <td >
            [...]
        </td>
        <td >
            [...]
        </td>
    </tr>
    <tr valign="top">
        <td>
            <strong>GUIGraph</strong>
        </td>
        <td >
            [...]
        </td>
        <td >
            [...]
        </td>
        <td >
            [...]
        </td>
    </tr>
</table>
-->