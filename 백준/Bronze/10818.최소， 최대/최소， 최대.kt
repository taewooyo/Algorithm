import java.io.IOException
import java.lang.*
import java.util.*

var sb = StringBuilder()
var br = System.`in`.bufferedReader()
var N = 0
fun main() {
    N = br.readLine().toInt()
    val list = br.readLine().split(" ").map { it.toInt() }
    print("${list.minOrNull()} ${list.maxOrNull()}")
}

