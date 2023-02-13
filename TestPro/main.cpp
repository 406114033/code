#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>
#include <vector>
#include "FFmpegHeaders.hpp"
#include <libavutil/timestamp.h>
#include <QDebug>
#include <algorithm>

static void log_packet(const AVFormatContext *fmt_ctx, const AVPacket *pkt, const char *tag) {
    AVRational *time_base = &fmt_ctx->streams[pkt->stream_index]->time_base;
//        printf("%s: pts:%s pts_time:%s dts:%s dts_time:%s duration:%s duration_time:%s stream_index:%d\n",
//               tag,
//               av_ts2str(pkt->pts), av_ts2timestr(pkt->pts, time_base),
//               av_ts2str(pkt->dts), av_ts2timestr(pkt->dts, time_base),
//               av_ts2str(pkt->duration), av_ts2timestr(pkt->duration, time_base),
//               pkt->stream_index);
}

void swap(vector<int> &nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
// -------------------一1111-----------------
//    for (int i = 0; i != n; ++i) {
//        nums1[m + i] = nums2[i];
//    }
//    sort(nums1.begin(), nums1.end(),greater<int>()); //从大到小
//    sort(nums1.begin(), nums1.end());  //从小到大

// ------------------2222------------------
//    int max = m + n -1;
//    for (int i = 0; i < n; ++i) {
//        nums1[m+i] =  nums2[i];
//    }
//    for (int i = 0; i < max; ++i) {
//        for (int j = 0; j < max - i; ++j) {
//            if(nums1[j+1] < nums1[j]){
//                int t = nums1[j+1];
//                nums1[j+1] =  nums1[j];
//                nums1[j] = t;
//            }
//        }
//    }

// -----------------33333----------------------
//    int i = 0,j = 0;
//    vector<int> result;
//    if(n == 0) return;
//    while(i < m && j < n){
//        if(nums1.at(i) > nums2.at(j)){
//            result.push_back(nums2.at(j));
//            j++;
//        }else{
//            result.push_back(nums1.at(i));
//            i++;
//        }
//    }
//    while(i < m){
//        result.push_back(nums1.at(i++));
//    }
//    while(j < n){
//        result.push_back(nums2.at(j++));
//    }
//    for (int k = 0; k < m+n; ++k) {
//        nums1[k] = result[k];
//    }

// ------------------44444-------------------
    int i = m - 1, j = n - 1, k = m + n - 1;
// 合并
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
// 合并剩余的nums2
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

void prin(int t) {
    qDebug() << t << ",";
}

void sortColors(vector<int> &nums) {
#if 1
    //双指针 同一方向对0 1 判断
    int n = nums.size();
    int p0 = 0, p1 = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1) {
            swap(nums[i], nums[p1]);
            ++p1;
        } else if (nums[i] == 0) {
            swap(nums[i], nums[p0]);
            if (p0 < p1) {
                swap(nums[i], nums[p1]);
            }
            ++p0;
            ++p1;
        }
        for_each(nums.begin(), nums.end(), prin);
        cout << endl;
    }
#endif

#if 0
    //双指针 相反方向判断 0 2  等于2时  防止nums[i]交换后还为2 需多次判断
    int p0 = 0,p2 = nums.size() -1;
    for (int i = 0; i <= p2; ++i) {
        while (i <= p2 && nums[i] == 2) {
            swap(nums[i], nums[p2]);
            --p2;
        }
        if(nums.at(i) == 0){
            swap(nums[i],nums[p0]);
            p0++;
        }
    }
#endif

#if 0
    //单指针循环两次
    int ptr = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums.at(i) == 0){
            swap(nums[i],nums[ptr]);
            ptr++;
        }
    }
    for (int i = ptr; i < nums.size(); ++i) {
        if(nums.at(i) == 1){
            swap(nums[i],nums[ptr]);
            ptr++;
        }
    }

#endif

#if 0
    //冒泡排序
    int max = nums.size() - 1;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max -i; ++j) {
            if(nums.at(j+1) < nums.at(j)){
                int t = nums.at(j+1);
                nums.at(j+1) = nums.at(j);
                nums.at(j) = t;
            }
        }
    }
#endif
}

void moveZeroes(vector<int> &nums) {
    int len = nums.size();
    int p0 = 0;
    for (int i = 0; i < len; ++i) {
        if (nums[i] != 0 && i >= p0) {
            swap(nums[i], nums[p0]);
            while (nums[p0] != 0) {
                p0++;
                if (p0 >= len) break;
            }
        }
        for_each(nums.begin(), nums.end(), prin);
        cout << endl;
    }
    int a = 0;
    for_each(nums.begin(), nums.end(), prin);

}

bool isPalindrome(string s) {
    string str;
#if 0
    for (int i = 0; i < s.size(); ++i) {
        char a = s.at(i);
        if(a >= 'A' && a <= 'Z'){
            str.push_back(a+32);
        }else if(a >= 'a' && a <= 'z'){
            str.push_back(a);
        }else if(a >= '0' && a <= '9'){
            str.push_back(a);
        }
    }
#endif

#if 0
    int len = str.size()-1;
        for (int i = 0,j = len; i <= len,j >= 0; ++i,--j) {
            if(str.at(i) != str.at(j)){
                cout << "false" << endl;
                return false;
            }
        }
        return true;
#endif

#if 1
    for (char a : s) {
        if (isalnum(a)) {
            str.push_back(a);
        }
    }
#endif

#if 1
    string strRev(str.rbegin(), str.rend());
    cout << 1;
    return str == strRev;
#endif

}

int findDuplicate(vector<int> &nums) {
    int ret = -1;
    int len = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (nums.at(i) == nums.at(j)) {
                ret = nums.at(i);
                break;
            }
        }
        if (ret > 0) break;
    }
    return ret;
}

//----冒泡排序-------比较相邻元素
void bubbleSort(vector<int> &nums) {
    int max = nums.size() - 1;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                int t = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = t;
            }
        }
    }
}

//选择起始位置最小  遍历后找到最小的下标 与最小值进行交换
//void selectionSort(vector<int> &nums) {
////    for (int i = 0; i < nums.size(); ++i) {
////        int minIndex = i;
////        for (int j = minIndex + 1; j < nums.size(); ++j) {
////            if (nums.at(j) < nums.at(minIndex)) {
////                minIndex = j;
////            }
////        }
////        swap(nums.at(i), nums.at(minIndex));
////    }
//}


//双指针 外层从左到右遍历  内层从排好序位置从右到左遍历
void insertionSort(vector<int> &nums) {
//    for (int i = 0; i < nums.size(); ++i) {
//        for (int j = i; j > 0; --j) {
//            if (nums[j] < nums[j - 1]) {
//                swap(nums[i], nums[j]); //因为初始 j == i 则
//            } else {
//                break;
//            }
//        }
//    }
}

#if 0
void mergeSort(vector<int> &nums, int l, int mid, int r) {
    vector<int> numCopy;
    if (numCopy.size() < nums.size()) {
        numCopy.resize(nums.size());
    }
    for (int i = l; i <= r; ++i) {
        qDebug() << " i = " << i << " nums.at(i) = " << nums.at(i);
        numCopy.at(i - l) = nums.at(i);
    }
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k) {
        if (i > mid) {
            nums[k] = numCopy[j - l];
            j++;
        } else if (j > r) {
            nums[k] = numCopy[i - l];
            i++;
        } else if (numCopy[i - l] < numCopy[j - l]) {
            qDebug() << " i -l = " << i - l << " j -l = " << j - l;
            nums[k] = numCopy[i - l];
            i++;
        } else {
            nums[k] = numCopy[j - l];
            j++;
        }
        qDebug() << " k = " << k << " nums[k] = " << nums[k];
    }
    for_each(nums.begin(),nums.end(),prin);
}
#endif

void merge(vector<int>& arr, int l, int mid, int r) {
    qDebug() << " l =  " << l << " mid = " << mid << " r = " << r;
    int index = 0;
    int ptrL = l;
    int ptrR = mid;
    static vector<int>tempary;
    if (arr.size() > tempary.size()) {
        tempary.resize(arr.size());
    }
    while (ptrL != mid && ptrR != r) {
        if (arr[ptrL] < arr[ptrR]) {
            tempary[index++] = arr[ptrL++];
        } else {
            tempary[index++] = arr[ptrR++];
        }
    }
    while (ptrL != mid) {
        tempary[index++] = arr[ptrL++];
    }
    while (ptrR != r) {
        tempary[index++] = arr[ptrR++];
    }
    copy(tempary.begin(), tempary.begin() + index, arr.begin() + l);
}
void mergeSort(vector<int>& arr, int l, int r) { // sort the range [l, r) in arr
    if (r - l <= 1) {
        return;
    }
    int mid = (l + r) / 2;
    qDebug() << " mergeSort 111111111" <<  " l = " << l << " mid = " << mid << " r = " << r;
    mergeSort(arr, l, mid);
    qDebug() << " mergeSort 222222222"<<  " l = " << l << " mid = " << mid << " r = " << r;
    mergeSort(arr, mid, r);
    qDebug() << " merge 3333"<<  " l = " << l << " mid = " << mid << " r = " << r;
    merge(arr, l, mid, r);
}


//----------------快速排序-------------
int partition(vector<int> &arr,int low,int high){

#if 0
    int ptrR = high;
    while(low <= ptrR){
        if(low == ptrR){
            swap(arr[low],arr[high]);
//            for_each(arr.begin(),arr.end(),prin);
            return low;
        }else if(arr[low] <= arr[high]){
            low++;
        }else if(arr[ptrR] >= arr[high]){
            ptrR--;
        }else if(arr[low] > arr[high] && arr[ptrR] < arr[high]){
            swap(arr[low],arr[ptrR]);
            low++;
            ptrR--;
        }
    }
#endif

#if 1
    int pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            --high;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
#endif
}

void quickSort(vector<int> &arr,int low,int high){
    if(low < high){
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
        qDebug() << " pivot = " << pivot;
        qDebug() << "-----------";
        for_each(arr.begin(),arr.end(),prin);
    }
}


//-----------------


int main(int argc, char **argv) {
    vector<int> nums1 = {3, 5, 8, 1, 2, 9, 4, 7,6};
    quickSort(nums1,0,8);
    qDebug() << "-----------";
    for_each(nums1.begin(),nums1.end(),prin);

//    int mid = 0 + (8 - 0) / 2;
//    mergeSort(nums1, 0,8);
//    selectionSort(nums1);
//    bubbleSort(nums1);
//    for_each(nums1.begin(), nums1.end(), prin);
    auto duplicate = findDuplicate(nums1);
    string s = "0P";
    auto res = isPalindrome(s);
    vector<int> nums2 = {1};
//    moveZeroes(nums1);
    int bbbbb = 0;
//    sortColors(nums1);
//    merge(nums1, 0, nums2, nums2.size());
    const AVOutputFormat *ofmt = NULL;
    AVFormatContext *ifmt_ctx = NULL, *ofmt_ctx = NULL;
    AVPacket *pkt = NULL;
    const char *in_filename, *out_filename;
    int ret, i;
    int stream_index = 0;
    int *stream_mapping = NULL;
    int stream_mapping_size = 0;

//    if (argc < 3) {
//        printf("usage: %s input output\n"
//               "API example program to remux a media file with libavformat and libavcodec.\n"
//               "The output format is guessed according to the file extension.\n"
//               "\n", argv[0]);
//        return 1;
//    }

    in_filename = "E:\\MP4\\big.mp4";
    out_filename = "E:\\big.mp4";

    pkt = av_packet_alloc();
    if (!pkt) {
        fprintf(stderr, "Could not allocate AVPacket\n");
        return 1;
    }

    if ((ret = avformat_open_input(&ifmt_ctx, in_filename, 0, 0)) < 0) {
        fprintf(stderr, "Could not open input file '%s'", in_filename);
        goto end;
    }

    if ((ret = avformat_find_stream_info(ifmt_ctx, 0)) < 0) {
        fprintf(stderr, "Failed to retrieve input stream information");
        goto end;
    }

    av_dump_format(ifmt_ctx, 0, in_filename, 0);

    avformat_alloc_output_context2(&ofmt_ctx, NULL, NULL, out_filename);
    if (!ofmt_ctx) {
        fprintf(stderr, "Could not create output context\n");
        ret = AVERROR_UNKNOWN;
        goto end;
    }

    stream_mapping_size = ifmt_ctx->nb_streams;
    stream_mapping = static_cast<int *>(av_calloc(stream_mapping_size, sizeof(*stream_mapping)));
    if (!stream_mapping) {
        ret = AVERROR(ENOMEM);
        goto end;
    }

    ofmt = ofmt_ctx->oformat;

    for (i = 0; i < ifmt_ctx->nb_streams; i++) {
        AVStream *out_stream;
        AVStream *in_stream = ifmt_ctx->streams[i];
        AVCodecParameters *in_codecpar = in_stream->codecpar;

        if (in_codecpar->codec_type != AVMEDIA_TYPE_AUDIO &&
            in_codecpar->codec_type != AVMEDIA_TYPE_VIDEO &&
            in_codecpar->codec_type != AVMEDIA_TYPE_SUBTITLE) {
            stream_mapping[i] = -1;
            continue;
        }

        stream_mapping[i] = stream_index++;

        out_stream = avformat_new_stream(ofmt_ctx, NULL);
        if (!out_stream) {
            fprintf(stderr, "Failed allocating output stream\n");
            ret = AVERROR_UNKNOWN;
            goto end;
        }

        ret = avcodec_parameters_copy(out_stream->codecpar, in_codecpar);
        if (ret < 0) {
            fprintf(stderr, "Failed to copy codec parameters\n");
            goto end;
        }
        out_stream->codecpar->codec_tag = 0;
    }
    av_dump_format(ofmt_ctx, 0, out_filename, 1);

    if (!(ofmt->flags & AVFMT_NOFILE)) {
        ret = avio_open(&ofmt_ctx->pb, out_filename, AVIO_FLAG_WRITE);
        if (ret < 0) {
            fprintf(stderr, "Could not open output file '%s'", out_filename);
            goto end;
        }
    }

    ret = avformat_write_header(ofmt_ctx, NULL);
    if (ret < 0) {
        fprintf(stderr, "Error occurred when opening output file\n");
        goto end;
    }

    while (1) {
        AVStream *in_stream, *out_stream;

        ret = av_read_frame(ifmt_ctx, pkt);
        if (ret < 0)
            break;

        in_stream = ifmt_ctx->streams[pkt->stream_index];
        if (pkt->stream_index >= stream_mapping_size ||
            stream_mapping[pkt->stream_index] < 0) {
            av_packet_unref(pkt);
            continue;
        }

        pkt->stream_index = stream_mapping[pkt->stream_index];
        out_stream = ofmt_ctx->streams[pkt->stream_index];
        log_packet(ifmt_ctx, pkt, "in");

        /* copy packet */
        av_packet_rescale_ts(pkt, in_stream->time_base, out_stream->time_base);
        pkt->pos = -1;
        log_packet(ofmt_ctx, pkt, "out");

        if (pkt->stream_index == 0) {
            qDebug() << "writePacket " << pkt->stream_index << " pts: " << pkt->pts;
        }

        ret = av_interleaved_write_frame(ofmt_ctx, pkt);
        /* pkt is now blank (av_interleaved_write_frame() takes ownership of
         * its contents and resets pkt), so that no unreferencing is necessary.
         * This would be different if one used av_write_frame(). */
        if (ret < 0) {
            fprintf(stderr, "Error muxing packet\n");
            break;
        }
    }

    av_write_trailer(ofmt_ctx);
    end:
    av_packet_free(&pkt);

    avformat_close_input(&ifmt_ctx);

    /* close output */
    if (ofmt_ctx && !(ofmt->flags & AVFMT_NOFILE))
        avio_closep(&ofmt_ctx->pb);
    avformat_free_context(ofmt_ctx);

    av_freep(&stream_mapping);

    if (ret < 0 && ret != AVERROR_EOF) {
//        fprintf(stderr, "Error occurred: %s\n", av_err2str(ret));
        return 1;
    }

    return 0;
}