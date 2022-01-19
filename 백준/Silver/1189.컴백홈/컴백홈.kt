import java.util.*
import kotlin.math.min

const val INF = 987654321
val br = System.`in`.bufferedReader()
val dy = intArrayOf(-1, 1, 0, 0)
val dx = intArrayOf(0, 0, -1, 1)
var r = 0
var c = 0
var k = 0
var graph = Array(10) {CharArray(10)}
val visited = Array(10) { IntArray(10) }

fun go(y:Int, x:Int): Int {
    if(y == 0 && x == c - 1) {
        return if(k == visited[y][x]) 1 else 0
    }
    var ret = 0
    for (i in 0 until 4) {
        val ny = y + dy[i]
        val nx = x + dx[i]
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] != 0 || graph[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[y][x] + 1
        ret += go(ny, nx)
        visited[ny][nx] = 0
    }
    return ret
}

fun main() {
    var token = StringTokenizer(br.readLine())
    r = token.nextToken().toInt()
    c = token.nextToken().toInt()
    k = token.nextToken().toInt()

    for(i in 0 until r) {
        val s = br.readLine()
        for (j in 0 until c) {
            graph[i][j] = s[j]
        }
    }

    visited[r-1][0] = 1
    println(go(r - 1, 0));
}