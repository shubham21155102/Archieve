const graph = {
  A: ['B', 'D'],
  B: ['A', 'C', 'E'],
  C: ['B'],
  D: ['A', 'E'],
  E: ['B', 'D', 'F'],
  F: ['E'],
};

function bfs(graph, start) {
  const queue = [start];
  const visited = new Set();
  const result = [];

  while (queue.length) {
    const vertex = queue.shift();

    if (!visited.has(vertex)) {
      visited.add(vertex);

      result.push(vertex);

      for (const neighbor of graph[vertex]) {
        queue.push(neighbor);
      }
      if (queue.length > 0) {
        result.push("\n");
      }
    }
  }

  return result;
}

const ans = bfs(graph, 'A');
console.log(ans.join('')); 
var t=[23,78,45,8,32,56];
t.shift();
console.log(t);