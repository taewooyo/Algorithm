import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val dy = intArrayOf(0, -1, 0, 1)
    val dx = intArrayOf(-1, 0, 1, 0)
    val room = IntArray(2505)
    var mx = 0
    var crashRoomSize = 0
    val (n, m) = br.readLine()!!.split(" ").map {it.toInt()}
    val visited = Array(m) {IntArray(n)}
    val graph = Array(m) {
        val st = StringTokenizer(br.readLine()!!)
        IntArray(n) {st.nextToken().toInt()}
    }

    fun dfs(y: Int, x: Int, num: Int) : Int {
        visited[y][x] = num
        var ret = 1
        for (i in 0 until 4) {
            if((graph[y][x] and (1 shl i)) == 0) {
                val ny = y + dy[i]
                val nx = x + dx[i]
                if (visited[ny][nx] != 0) continue
                ret += dfs(ny, nx, num)
            }
        }
        return ret
    }

    var roomCnt = 0
    for (i in 0 until m) {
        for (j in 0 until n) {
            if(visited[i][j] == 0) {
                roomCnt++
                room[roomCnt] = dfs(i, j, roomCnt)
                mx = mx.coerceAtLeast(room[roomCnt]) // 가장 큰 방 찾기
            }
        }
    }

    for (i in 0 until m) {
        for (j in 0 until n) {
            if(i+1 < m) {
                val a = visited[i+1][j]
                val b = visited[i][j]
                if(a != b)
                    crashRoomSize = crashRoomSize.coerceAtLeast(room[a] + room[b])
            }
            if(j+1 < n) {
                val a = visited[i][j+1]
                val b = visited[i][j]
                if(a != b)
                    crashRoomSize = crashRoomSize.coerceAtLeast(room[a] + room[b])
            }
        }
    }
    println("$roomCnt\n$mx\n$crashRoomSize")
}