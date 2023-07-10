#include <iostream>

using namespace std;

#include <cstdlib>
#include <string>
#include <vector>
#include "FFmpegHeaders.hpp"
#include <libavutil/timestamp.h>
#include <QDebug>
#include <algorithm>
#include "Logger.hpp"
#include "dbg.h"
#include "QApplication"
#include "MainWindow.hpp"

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
//实现可以用双层循环, 外层用来控制内层循环中最值上浮的位置, 内层用来进行两两比较和交换位置.
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

void bubleSort(vector<int> &nums) {
    int max = nums.size() - 1;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
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

void selectionSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int minIndex = i;
        for (int j = minIndex + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}


//双指针 外层从左到右遍历  内层从排好序位置从右到左遍历
void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = i; j > 0; --j) {
            if (nums.at(j) < nums.at(j - 1)) {
                //因为初始 j == i , i是未进行排序的,从i开始逆向比较 若小于前一个则进行交换，实现插入
                swap(nums.at(j), nums.at(j - 1));
            } else {
                break;
            }
        }
    }
}


void insertionSort1(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            if (nums.at(j) < nums.at(j - 1)) {
                swap(nums[j], nums[j - 1]);
            } else {
                break;
            }
        }
    }
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

void merge(vector<int> &arr, int l, int mid, int r) {
    qDebug() << " l =  " << l << " mid = " << mid << " r = " << r;
    int index = 0;
    int ptrL = l;
    int ptrR = mid;
    static vector<int> tempary;
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

void mergeSort(vector<int> &arr, int l, int r) { // sort the range [l, r) in arr
    if (r - l <= 1) {
        return;
    }
    int mid = (l + r) / 2;
    qDebug() << " mergeSort 111111111" << " l = " << l << " mid = " << mid << " r = " << r;
    mergeSort(arr, l, mid);
    qDebug() << " mergeSort 222222222" << " l = " << l << " mid = " << mid << " r = " << r;
    mergeSort(arr, mid, r);
    qDebug() << " merge 3333" << " l = " << l << " mid = " << mid << " r = " << r;
    merge(arr, l, mid, r);
}


//----------------快速排序-------------
//选择 最左边为左标记，最右边为右标记且为基准，同向遍历，左标记大于基准，右标记小于基准时，交换两个值，左标与下标相等时，将其与基准交换，
//(此时基准左边为小于基准的，右边为大于基准的)
//然后递归的对左右两边完成快速排序。
int partition(vector<int> &arr, int low, int high) {

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

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
        qDebug() << " pivot = " << pivot;
        qDebug() << "-----------";
        for_each(arr.begin(), arr.end(), prin);
    }
}


//-----------------
int partition1(vector<int> &arr, int low, int high) {
    int temp = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= temp) {
            high--;
        }
        qDebug() << " =======high = " << high << " low = " << low;
        arr[low] = arr[high];
        while (low < high && arr[low] <= temp) {
            low++;
        }
        qDebug() << " high = " << high << " low = " << low;
        arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
}

void quickSort1(vector<int> &arr, int low, int high) {
    if (low < high) {
        int privot = partition1(arr, low, high);
        quickSort1(arr, low, privot - 1);
        quickSort1(arr, privot + 1, high);
    }
}

class Person {
public:
    Person() noexcept {
        qDebug() << "Person+++++++";
        mNum += n;
        n++;
    }

    ~Person() {
        qDebug() << "Person------";
    }

    void add() {
        qDebug() << "add";
    }

    int n = 1;
    int mNum;
};


static int io_interrupt_cb(void *ctx) {
    // 这个函数写AVPacket时一直在被调用，不要把磁盘容量检查放在这里
    return 0;
}

class CBase{
public:
    virtual int test(){
        return 0;
    }

private:
    int mDddd = 6;
};

class CDerived : public CBase{
public:
    int test() override{
        return 1;
    }
};

void typeConverterCast() {
    int a = 3;
    int b = 10;
    auto d = b / a;
    auto c = static_cast<char>(b / a);
    LOG_I << " c = " << to_string(c);
    int *intP = &b;
    void *voidP = static_cast<void *>(intP);
//    LOG_I << " *voidP = " << *voidP;
    long *pDouble = static_cast<long *>(voidP);
    LOG_I << " pDouble = " << *pDouble;

    CDerived * tcDerived = new CDerived;
    CBase * tcBase = static_cast<CBase *>(tcDerived);

    CDerived *tcDerived1 = static_cast<CDerived*>(tcBase);  //不会报错 但不安全
    CDerived *tcDerived2 = dynamic_cast<CDerived*>(tcBase);

    CDerived i_CBase;
    CBase &r_CBase = i_CBase;
    try{
        CDerived &r_CDerived = dynamic_cast<CDerived &>(r_CBase);
    }catch (std::bad_cast &e){
        LOG_I << " 类型转换失败";
    }


    int value = 100;
    const int *cPi = &value;
//    *cPi = 200;
    int *pi = const_cast<int *>(cPi);
    LOG_I << "=======" << *pi;
    *pi = 200;
    LOG_I << "=======" << *pi;
    const int *cpi2 = const_cast<const int *>(pi);
//    cpi2 = 300;
    const int value1 = 500;
    const int &cValue = value1;
    int &rValue = const_cast<int &>(cValue);
    rValue = 1000;

    const int &cValue2 = const_cast<const int &>(rValue);

    int num = 100;
    int *ppNum = &num;
    int numValue = reinterpret_cast<int>(ppNum);
    int *pNum = reinterpret_cast<int *>(num);
    int numm = reinterpret_cast<int>(pNum);



//    float * pInt = static_cast<float *>(pDouble);  error
    LOG_I << " end ";
}

class MyClass {
public:
    void constttt() const;

    void constMemberFunction() const;

private:
    mutable int constantVariable = 0;
//    int constantVariable = 0;
    int a = 0;
};

void MyClass::constttt() const{
    constantVariable = 20;
}

void MyClass::constMemberFunction() const {
    const_cast<int&>(constantVariable) = 42; // 修改 const 成员变量的值
    LOG_I << "constandVariable = " << constantVariable;
    constttt();
    LOG_I << "constandVariable = " << constantVariable;
}

int main(int argc, char **argv) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(720,640);
    w.show();

    return a.exec();
#if 0
    TaiShan::initLogger("d:/","newTestDemo");
    float outData[3084] = {};
    auto size = sizeof(outData);
    MyClass claObj;
    claObj.constMemberFunction();
    typeConverterCast();
    std::unique_ptr<Person> ptrU(new Person);
    auto pppp = ptrU.release();
    pppp->add();
    std::shared_ptr<Person> ptr1(new Person[5]{}, [](Person *person) {
        person->mNum = 2;
        person->add();
    });
    std::shared_ptr<Person> ptr2(ptr1);
    LOG_I << ptr1.use_count();
//    dbg(ptr1.use_count());
    ptr2.reset();
    LOG_I << ptr1.use_count() << endl;

    vector<int> nums1 = {3, 5, 8, 1, 2, 9, 4, 7, 6};
//    insertionSort(nums1);
    quickSort1(nums1, 0, 8);
    qDebug() << "-----------";
    for_each(nums1.begin(), nums1.end(), prin);
    qDebug() << "-----------";
    qDebug() << "-----------";

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
#endif
//    sortColors(nums1);
//    merge(nums1, 0, nums2, nums2.size());


#if 0   //-------------ffmpegDemo-----------
    const AVOutputFormat *ofmt = NULL;
    AVFormatContext *ifmt_ctx = NULL, *ofmt_ctx = NULL;
    AVPacket *pkt, *newPkt = NULL;
    const char *in_filename, *out_filename;
    int ret, i;
    int stream_index = 0;
    int *stream_mapping = NULL;
    int stream_mapping_size = 0;
    AVFrame *frame = NULL;

//    if (argc < 3) {
//        printf("usage: %s input output\n"
//               "API example program to remux a media file with libavformat and libavcodec.\n"
//               "The output format is guessed according to the file extension.\n"
//               "\n", argv[0]);
//        return 1;
//    }

    in_filename = "E:\\MP4\\big.mp4";
    out_filename = "E:\\MP4\\test-big-ffmpeg.avi";

    pkt = av_packet_alloc();
    newPkt = av_packet_alloc();
    if (!pkt) {
        fprintf(stderr, "Could not allocate AVPacket\n");
        return 1;
    }
//demuxer
    if ((ret = avformat_open_input(&ifmt_ctx, in_filename, 0, 0)) < 0) {
        fprintf(stderr, "Could not open input file '%s'", in_filename);
        goto end;
    }

    if ((ret = avformat_find_stream_info(ifmt_ctx, 0)) < 0) {
        fprintf(stderr, "Failed to retrieve input stream information");
        goto end;
    }

    av_dump_format(ifmt_ctx, 0, in_filename, 0);


//muxer
    avformat_alloc_output_context2(&ofmt_ctx, NULL, NULL, out_filename);
    if (!ofmt_ctx) {
        fprintf(stderr, "Could not create output context\n");
        ret = AVERROR_UNKNOWN;
        goto end;
    }

    stream_mapping_size = ifmt_ctx->nb_streams;
    stream_mapping = (int *) (av_calloc(stream_mapping_size, sizeof(*stream_mapping)));
    if (!stream_mapping) {
        ret = AVERROR(ENOMEM);
        goto end;
    }

    ofmt = ofmt_ctx->oformat;

//addStream
    AVStream *out_stream;
    AVStream *in_stream = ifmt_ctx->streams[0];
    AVCodecParameters *in_codecpar = in_stream->codecpar;

    if (in_codecpar->codec_type != AVMEDIA_TYPE_AUDIO &&
        in_codecpar->codec_type != AVMEDIA_TYPE_VIDEO &&
        in_codecpar->codec_type != AVMEDIA_TYPE_SUBTITLE) {
        stream_mapping[0] = -1;
        return 0;
    }

    stream_mapping[0] = stream_index++;
//Decoder
    const AVCodec *decodeCodec = NULL;
    if (!decodeCodec) {
        decodeCodec = avcodec_find_decoder(in_codecpar->codec_id);
    }
    if (!decodeCodec) {
        goto end;
    }

    AVCodecContext *decodeCodecCtx = avcodec_alloc_context3(decodeCodec);
    if (!decodeCodecCtx) {
        goto end;
    }

    int result = avcodec_parameters_to_context(decodeCodecCtx, in_codecpar);

    result = avcodec_open2(decodeCodecCtx, NULL, NULL);


//encoder
    const AVCodec *encodeCodec = NULL;
    encodeCodec = avcodec_find_encoder(AV_CODEC_ID_H264);
    if (!encodeCodec) {
        goto end;
    }

    AVCodecContext *encodeCodecCtx = avcodec_alloc_context3(encodeCodec);
    encodeCodecCtx->bit_rate = in_codecpar->bit_rate;
//encodeCodecCtx->sample_rate = decodeCodecCtx->sample_rate;
//encodeCodecCtx->sample_fmt = decodeCodecCtx->sample_fmt;
//encodeCodecCtx->channels = decodeCodecCtx->channels;
    encodeCodecCtx->width = in_codecpar->width;
    encodeCodecCtx->height = in_codecpar->height;
    encodeCodecCtx->pix_fmt = (AVPixelFormat)in_codecpar->format;
    encodeCodecCtx->time_base = av_make_q(in_stream->avg_frame_rate.den,in_stream->avg_frame_rate.num);
    encodeCodecCtx->framerate = in_stream->avg_frame_rate;
//encodeCodecCtx->channel_layout = decodeCodecCtx->channel_layout;
    encodeCodecCtx->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
    encodeCodecCtx->trellis = 1;

    result = avcodec_open2(encodeCodecCtx, encodeCodec, NULL);
    if (result) {
        goto end;
    }


    out_stream = avformat_new_stream(ofmt_ctx, NULL);
    if (!out_stream) {
        fprintf(stderr, "Failed allocating output stream\n");
        ret = AVERROR_UNKNOWN;
        goto end;
    }

    out_stream->id = ofmt_ctx->nb_streams - 1;
    ret = avcodec_parameters_from_context(out_stream->codecpar, encodeCodecCtx);
    if (ret < 0) {
        fprintf(stderr, "Failed to copy codec parameters\n");
        goto end;
    }
//out_stream->time_base = encodeCodecCtx->time_base;
    out_stream->codecpar->codec_tag = 0;
    out_stream->avg_frame_rate = in_stream->avg_frame_rate;
    uint8_t *data = av_stream_new_side_data(out_stream, AV_PKT_DATA_NEW_EXTRADATA, 34);

    av_dump_format(ofmt_ctx, 0, out_filename, 1);


//writeHead

//    const AVIOInterruptCB int_cb = {io_interrupt_cb,this};

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

    frame = av_frame_alloc();
    while (1) {
        ret = av_read_frame(ifmt_ctx, pkt);
        if (ret < 0)
            break;

        ret = avcodec_send_packet(decodeCodecCtx, pkt);
        if (ret < 0 && AVERROR_EOF != ret) {
            continue;
        }
        ret = avcodec_receive_frame(decodeCodecCtx, frame);

        if (frame) {
            avcodec_send_frame(encodeCodecCtx, frame);
        }

        ret = avcodec_receive_packet(encodeCodecCtx, newPkt);

        /* copy packet */
        av_packet_rescale_ts(newPkt, in_stream->time_base, out_stream->time_base);
        newPkt->pos = -1;
        //        log_packet(ofmt_ctx, pkt, "out");

        if (newPkt->stream_index == 0) {
            //qDebug() << "writePacket " << pkt->stream_index << " pts: " << pkt->pts;
        }

        ret = av_interleaved_write_frame(ofmt_ctx, newPkt);
        /* pkt is now blank (av_interleaved_write_frame() takes ownership of
         * its contents and resets pkt), so that no unreferencing is necessary.
         * This would be different if one used av_write_frame(). */
        if (ret < 0) {
            fprintf(stderr, "Error muxing packet\n");
            continue;
        }
    }

    av_write_trailer(ofmt_ctx);
    end:
    av_packet_free(&pkt);
    av_packet_free(&newPkt);
    av_frame_free(&frame);

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
#endif

    return 0;
}