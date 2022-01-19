import java.lang.*
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val str = StringBuilder()

    var (h : Int, m : Int) = br.readLine().split(" ").map { it.toInt() }

    if(m < 45) {
        h--
        m = 60 - (45 - m)
        if(h < 0) h = 23
        str.append("$h $m")
    }
    else str.append("$h ${m-45}")

    println(str.toString())
    br.close()
}