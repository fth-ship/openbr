#include <opencv2/video/tracking.hpp>
#include "openbr_internal.h"

using namespace cv;

namespace br
{

/*!
 * \ingroup transforms
 * \brief Gets a two-channel dense optical flow from an image
 * \author Austin Blanton \cite imaus10
 */
class OpticalFlowTransform : public UntrainableTransform
{
	Q_OBJECT
	// these defaults are optimized for KTH
	Q_PROPERTY(double pyr_scale READ get_pyr_scale WRITE set_pyr_scale RESET reset_pyr_scale STORE false)
	BR_PROPERTY(double, pyr_scale, 0.1)
	Q_PROPERTY(int levels READ get_levels WRITE set_levels RESET reset_levels STORE false)
	BR_PROPERTY(int, levels, 1)
	Q_PROPERTY(int winsize READ get_winsize WRITE set_winsize RESET reset_winsize STORE false)
	BR_PROPERTY(int, winsize, 5)
	Q_PROPERTY(int iterations READ get_iterations WRITE set_iterations RESET reset_iterations STORE false)
	BR_PROPERTY(int, iterations, 10)
	Q_PROPERTY(int poly_n READ get_poly_n WRITE set_poly_n RESET reset_poly_n STORE false)
	BR_PROPERTY(int, poly_n, 7)
	Q_PROPERTY(double poly_sigma READ get_poly_sigma WRITE set_poly_sigma RESET reset_poly_sigma STORE false)
	BR_PROPERTY(double, poly_sigma, 1.1)
	Q_PROPERTY(int flags READ get_flags WRITE set_flags RESET reset_flags STORE false)
	BR_PROPERTY(int, flags, 0)

	void project(const Template &src, Template &dst) const
	{
		// TODO: get the two images from AggregateFrames
		calcOpticalFlowFarneback(prevImg, nextImg, dst, pyr_scale, levels, winsize, iterations, poly_n, poly_sigma, flags);
	}
};

BR_REGISTER(Transform, OpticalFlowTransform)

} // namespace br

#include "opticalflow.moc"