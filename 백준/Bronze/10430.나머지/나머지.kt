import java.io.IOException
import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    var token: StringTokenizer? = null
    token = StringTokenizer(br.readLine())

    val A = token.nextToken().toInt()
    val B = token.nextToken().toInt()
    val C = token.nextToken().toInt()
    bw.write( ((A+B)%C).toString())
    bw.newLine()
    bw.write( (((A%C) + (B%C))%C).toString())
    bw.newLine()
    bw.write( ((A*B)%C).toString())
    bw.newLine()
    bw.write( (((A%C) * (B%C))%C).toString())
    br.close()
    bw.close()
}
