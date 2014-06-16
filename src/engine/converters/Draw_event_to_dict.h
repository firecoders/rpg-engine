/* rpg-engine, An rpg engine written in C++
   Copyright (C) 2014 firecoders

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
   DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
   OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef ENGINE_CONVERTERS_DRAW_EVENT_TO_DICT_GUARD
#define ENGINE_CONVERTERS_DRAW_EVENT_TO_DICT_GUARD

#include <memory>
#include <string>

#include "engine/events/interfaces/Listener.h"
#include "engine/gui/Draw_event.h"
#include "engine/types/Dict.h"

namespace engine
{
    namespace converters
    {
        class Draw_event_to_dict : public events::Listener< std::shared_ptr < gui::Draw_event > >
        {
            public:
                Draw_event_to_dict ( events::Listener< std::shared_ptr< types::Dict > >* listener );

                void handle_event ( std::shared_ptr < gui::Draw_event > draw_event );

            private:
                events::Listener< std::shared_ptr< types::Dict > >* listener;
        };
    } /* namespace converters */
} /* namespace engine */

#endif // ENGINE_CONVERTERS_DRAW_EVENT_TO_DICT_GUARD