import java.lang.*
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val str = StringBuilder()

    val x = br.readLine().toInt()
    val y = br.readLine().toInt()

    val answer = if(x > 0 && y > 0) {
        1
    }
    else if(x > 0 && y < 0) {
        4
    }
    else if(x < 0 && y > 0) {
        2
    }
    else {
        3
    }

    str.append("$answer")
    println(str.toString())
    br.close()
}