class Solution {

/**
 * @param String[] $strs
 * @return String
 */
function longestCommonPrefix($strs) {
    $check = $strs[0];

    $res = "";
    if(count($strs) <= 1 || strlen($strs[0]) == 0){
        return $strs[0];
    }

    for($i = 1; $i < count($strs); $i++){
        $res = "";
        for($j = 0; $j < strlen($strs[$i]); $j++){
            if($check[$j] === $strs[$i][$j]){
                $res .= $strs[$i][$j];
            } else {
                break;
            }
        }
        $check = $res;
    }
    return $res;
}
}

// Take inputs from the user
echo "Enter strings separated by space: ";
$input = trim(fgets(STDIN));
$strs = explode(" ", $input);

$solution = new Solution();
$result = $solution->longestCommonPrefix($strs);
echo "Longest Common Prefix: " . $result;
