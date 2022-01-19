import java.util.*
import kotlin.math.min

const val INF = 987654321
val br = System.`in`.bufferedReader()
var n = 0
var flower = Array(14) {Array<Int>(14) {0} }
var visited = Array(14) {Array<Int>(14) {0} }
var dy = intArrayOf(-1, 1, 0, 0)
var dx = intArrayOf(0, 0, -1, 1)
var ret = INF


fun check(y: Int, x: Int): Boolean {
    if(visited[y][x] != 0) return false
    for (i in 0..3) {
        var ny = y + dy[i]
        var nx = x + dx[i]
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx] != 0)
            return false;
    }
    return true;
}

fun setFlower(y: Int, x: Int): Int {
    visited[y][x] = 1
    var ret = flower[y][x]
    for (i in 0..3) {
        var ny = y + dy[i]
        var nx = x + dx[i]
        visited[ny][nx] = 1
        ret += flower[ny][nx]
    }
    return ret
}

fun eraseFlower(y: Int, x:Int) {
    visited[y][x] = 0
    for (i in 0..3) {
        var ny = y + dy[i]
        var nx = x + dx[i]
        visited[ny][nx] = 0
    }
}

fun go(cnt: Int, hap: Int) {
    if(cnt == 3) {
        ret = min(ret, hap);
        return;
    }

    for (i in 0 until n) {
        for (j in 0 until n) {
            if(check(i, j)) {
                go(cnt+1, hap + setFlower(i, j))
                eraseFlower(i, j)
            }
        }
    }
}

fun main() {
    var token = StringTokenizer(br.readLine())
    n = token.nextToken().toInt()

    for (i in 0 until n) {
        token = StringTokenizer(br.readLine())
        for (j in 0 until n) {
            flower[i][j] = token.nextToken().toInt()
        }
    }

    go(0, 0)
    println(ret)
}