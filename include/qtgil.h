#ifndef QTGIL_H
#define QTGIL_H
#include <qimage.h>
#include "boost/gil/gil_all.hpp"

namespace QT_GIL
{
    typedef unsigned char byte;

    QColor _argb_QColor (byte a, byte r, byte g, byte b) { return QColor(r, g, b, a); }

    QImage* create_QImage_argb32 (boost::gil::argb32_view_t& g)
    {
        QImage *q = new QImage(g.width(), g.height(), QImage::Format_ARGB32);

        typedef boost::gil::image_view<gLocType> VIEW;
        typedef boost::gil::channel_type<VIEW>::type CHANNEL_TYPE;
        typedef boost::gil::color_space_type<VIEW>::type COLOR_SPACE;
        typedef boost::gil::pixel<CHANNEL_TYPE, boost::gil::layout<COLOR_SPACE>> PIXEL;
        std::vector<PIXEL> row(g.width());

        for(int y=0; y < g.height(); y++)
        {
            std::copy(view.row_begin(y), view.row_end(y), row.begin());
            byte* b = (byte*) &row.front();
            while(b) q->setPixelColor(x,y, _argb_QColor(b+0, b+1, b+2, b+3)), b+=4;
        }

        return q;
    }

    QImage* create_QImage_rgb32 (boost::gil::rgb32_view_t& g)
    {
        QImage *q = new QImage(g.width(), g.height(), QImage::Format_RGB32);

        typedef boost::gil::image_view<gLocType> VIEW;
        typedef boost::gil::channel_type<VIEW>::type CHANNEL_TYPE;
        typedef boost::gil::color_space_type<VIEW>::type COLOR_SPACE;
        typedef boost::gil::pixel<CHANNEL_TYPE, boost::gil::layout<COLOR_SPACE>> PIXEL;
        std::vector<PIXEL> row(g.width());

        for(int y=0; y < g.height(); y++)
        {
            std::copy(view.row_begin(y), view.row_end(y), row.begin());
            byte* b = (byte*) &row.front();
            while(b) q->setPixelColor(x,y, _argb_QColor(255, b+0, b+1, b+2)), b+=4;
        }

        return q;
    }

    QImage* create_QImage_gray8 (boost::gil::gray8_view_t& g)
    {
        QImage *q = new QImage(g.width(), g.height(), QImage::Format_Grayscale8);

        typedef boost::gil::image_view<gLocType> VIEW;
        typedef boost::gil::channel_type<VIEW>::type CHANNEL_TYPE;
        typedef boost::gil::color_space_type<VIEW>::type COLOR_SPACE;
        typedef boost::gil::pixel<CHANNEL_TYPE, boost::gil::layout<COLOR_SPACE>> PIXEL;
        std::vector<PIXEL> row(g.width());

        for(int y=0; y < g.height(); y++)
        {
            std::copy(view.row_begin(y), view.row_end(y), row.begin());
            byte* b = (byte*) &row.front();
            while(b) q->setPixelColor(x,y, _argb_QColor(255, b+0, b+0, b+0)), b+=1;
        }

        return q;
    }


}

#endif // QTGIL_H
