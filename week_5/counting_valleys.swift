import Foundation

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

func countingValleys(steps: Int, path: String) -> Int {
    // Write your code here
    var altitude = 0
    
    return path.reduce(0, { valleysWalkedThrough, newStep in
        let isGoingDown = newStep == "D"
        let isAtSeaLevel = altitude == 0
        
        altitude = altitude + (isGoingDown ? -1 : 1)
        
        return isAtSeaLevel && isGoingDown ? valleysWalkedThrough + 1 : valleysWalkedThrough
    })

}

let stdout = ProcessInfo.processInfo.environment["OUTPUT_PATH"]!
FileManager.default.createFile(atPath: stdout, contents: nil, attributes: nil)
let fileHandle = FileHandle(forWritingAtPath: stdout)!

guard let steps = Int((readLine()?.trimmingCharacters(in: .whitespacesAndNewlines))!)
else { fatalError("Bad input") }

guard let path = readLine() else { fatalError("Bad input") }

let result = countingValleys(steps: steps, path: path)

fileHandle.write(String(result).data(using: .utf8)!)
fileHandle.write("\n".data(using: .utf8)!)