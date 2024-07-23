### 提取pcm数据 
    ffmpeg -i wuniang.mp4 -ac 2 -ar 44100 -f s16le -acodec pcm_s16le -frame_size 1024 -y output_44100_2_s16le.pcm
### 播放pcm数据 
    ffplay input.pcm -ch_layout stereo -ar 44100 -f s16le output_44100_2_s16le.pcm

### ffmpeg解复用
    avformat_alloc_context() 申请一个AVFormatContext结构

    avformat_open_input() 打开本地文件或网络流

    avformat_find_stream_info() 查找容器内流的信息

    av_read_frame() 读取AVPacket 读取音视频包

    av_format_seek_file() 定位文件 时间戳PTS

    av_seek_frame() 定位文件 文件size

    avformat_close_input() 关闭

### ffmpeg解码器
    avcodec_alloc_context3() 分配解码器上下文 
    
    avcodec_find_decoder() 根据id查找解码器 

    avcodec_find_decoder_by_name()

    avcodec_open2() 打开解码器

    avcodec_send_packet() 发送编码数据包

    avcodec_receive_frame() 接收解码后的数据

    avcodec_free_context() 释放解码器上下文 已经包含了avcodec_close()

    avcodec_close() 关闭解码器 
