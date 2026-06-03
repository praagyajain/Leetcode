class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        if n == 0: 
            return 0
        
        # Determine the alphabet of characters that actually appear in s to optimize
        valid_chars = sorted(list(set(ord(c) - 97 for c in s)))
        num_valid = len(valid_chars)
        bit = [1 << i for i in range(26)]
        
        # P[k][c] will store the frequency of character 'c' in the prefix s[0...k-1]
        P = [[0] * 26 for _ in range(n + 1)]
        for i in range(n):
            for j in range(26):
                P[i + 1][j] = P[i][j]
            P[i + 1][ord(s[i]) - 97] += 1
            
        min_idx1 = {}
        
        # Pass 1: Build the hash map of signatures looking forward from `idx1`
        future_chars = []
        for idx1 in range(n - 1, -1, -1):
            c = ord(s[idx1]) - 97
            if c in future_chars:
                future_chars.remove(c)
            future_chars.insert(0, c)  # Keep tracked by chronological First Occurrences
            
            mask_val = 0
            P1 = P[idx1]
            for fc in future_chars:
                mask_val |= bit[fc]
                c0 = (mask_val & -mask_val).bit_length() - 1  # Get lowest set bit
                
                # Compute signature tuple
                val = [0] * num_valid
                for k, i in enumerate(valid_chars):
                    if mask_val & bit[i]:
                        val[k] = P1[i] - P1[c0]
                    else:
                        val[k] = P1[i]
                sig = tuple(val)
                
                if mask_val not in min_idx1:
                    min_idx1[mask_val] = {}
                # Going backwards guarantees min_idx1 keeps the lowest possible absolute idx1
                min_idx1[mask_val][sig] = idx1
                
        max_len = 0
        past_chars = []
        
        # Pass 2: Query the hash map of signatures looking backward from `idx2`
        for idx2 in range(1, n + 1):
            c = ord(s[idx2 - 1]) - 97
            if c in past_chars:
                past_chars.remove(c)
            past_chars.insert(0, c)    # Keep tracked by chronological Last Occurrences
            
            mask_val = 0
            P2 = P[idx2]
            for pc in past_chars:
                mask_val |= bit[pc]
                c0 = (mask_val & -mask_val).bit_length() - 1
                
                val = [0] * num_valid
                for k, i in enumerate(valid_chars):
                    if mask_val & bit[i]:
                        val[k] = P2[i] - P2[c0]
                    else:
                        val[k] = P2[i]
                sig = tuple(val)
                
                # Try locating the minimum valid start sequence bounded by this mask
                if mask_val in min_idx1 and sig in min_idx1[mask_val]:
                    idx1 = min_idx1[mask_val][sig]
                    if idx1 < idx2:
                        length = idx2 - idx1
                        if length > max_len:
                            max_len = length
                            
        return max_len