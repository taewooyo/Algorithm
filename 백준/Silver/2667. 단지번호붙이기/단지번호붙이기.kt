import java.util.*

val dy = intArrayOf(0, 0, 1, -1)
val dx = intArrayOf(1, -1, 0, 0)
fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val graph = Array(n) { br.readLine().map { it - '0' } }
    val visited = Array(n) { BooleanArray(n) { false } }
    val answer = mutableListOf<Int>()


    for (i in graph.indices) {
        for (j in 0 until graph[i].size) {
            if (!visited[i][j] && graph[i][j] == 1) answer.add(bfs(i, j, visited, n, graph))
        }
    }

    println("${answer.size}\n${answer.sorted().joinToString("\n")}")
}

fun bfs(y: Int, x: Int, visited: Array<BooleanArray>, n: Int, graph: Array<List<Int>>): Int {
    var ret = 1
    val queue: Queue<Pair<Int, Int>> = LinkedList<Pair<Int, Int>>()
    queue.add(Pair(y ,x))
    visited[y][x] = true

    while(queue.isNotEmpty()) {
        val (y, x) = queue.poll()
        for (i in 0 until 4) {
            val ny = y + dy[i]
            val nx = x + dx[i]
            if (inRange(ny ,nx, n) && !visited[ny][nx] && graph[ny][nx] == 1) {
                queue.add(Pair(ny, nx))
                ret += 1
                visited[ny][nx] = true
            }
        }
    }
    return ret
}

fun inRange(y: Int, x: Int, n: Int): Boolean = y >= 0 && x >= 0 && y < n && x < n
