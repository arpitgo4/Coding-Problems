// Let's Watch Football (https://codeforces.com/problemset/problem/195/A)
 
#include <iostream>
#include <vector>
 
using namespace std;
 
// Time: O(logN)
// Space: O(1)

4 1 1
4 bytes to download 1 second of video at 1 byte/sec;
 
bool can_watch(int time, int data_packet_size, int download_speed, int video_len) {
    int video_time = (time * download_speed) / data_packet_size;
    int video_download_in_video_time = (video_time * download_speed) / data_packet_size;

    return video_download_in_video_time >= video_time;
}

void solve(int data_packet_size, int download_speed, int video_len) {
    int l = 1, h = 1e7;
    while (l <= h) {
        int m = (h-l)/2 + l;
        if (can_watch(m, data_packet_size, download_speed, video_len))
            h = m-1;
        else l = m+1;
    }

    cout << l;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int data_packet_size, download_speed, video_len;
    cin >> data_packet_size >> download_speed >> video_len;

    solve(data_packet_size, download_speed, video_len);   
    
    return 0;
}